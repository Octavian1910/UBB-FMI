bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit ,fopen,fclose              ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import fopen msvcrt.dll
import fclose msvcrt.dll
                          
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    nume_fisier db "ana.txt",0
    mod_acces db "w",0
    
    descriptor_fis dd -1

; our code starts here
segment code use32 class=code
    start:
        ;fopen(nume,mod_acces)
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp,4*2

        mov [descriptor_fis],eax
        
        cmp eax,0
        je final
        
        ;fclose(descriptor)
        push dword[descriptor_fis]
        call [fclose]
        add esp,4
        
        
        final:
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
