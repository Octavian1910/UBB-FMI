bits 32 ; assembling for the 32 bits architecture
;Se da un sir de numere. Sa se afiseze valorile in baza 16 si in baza 2.


; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
extern baza2,baza16
                          
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    sir db 11,12,45,78,65
    len equ $-sir

; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;baza2(sir,len)
        push len
        push sir
        call baza2
        
        ;baza16(sir,len)
        push len
        push sir
        call baza16
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
