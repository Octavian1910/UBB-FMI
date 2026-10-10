bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    nume_fisier db "ana.txt",0
    mod_acces db "r",0
    len equ 100
    text times len db 0
    descriptor dd -1
    format "Am citit %d caractere din fisier.Textul este %s",0
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;fopen(nume_fisier,mod_acces)
        push mod_acces
        push nume_fisier
        call [fopen]
        add esp,4*2
        
        mov [descriptor],eax
        cmp eax,0
        je finish
        
        ;eax = nr_cuv( fread(text,1,len,descriptor) )
        push dword [descriptor]
        push dword len
        push 1
        push text
        call [fread]
        add esp,4*4
        
        ;printf(format,eax,text)
        push dword text
        push eax
        push format
        call [printf]
        add esp,4*3
        
        ;fclose(descriptor)
        push dword [descriptor]
        call [fclose]
        add esp,4
          
        
        finish:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
