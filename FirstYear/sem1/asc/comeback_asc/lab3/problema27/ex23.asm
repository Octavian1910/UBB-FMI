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
    ;(100+a+b*c)/(a-100)+e+x/a; 
    ;a,b-byte; c-word; e-doubleword; x-qword
    
    a db 75
    b db 2
    c dw 45
    e dd 8
    x dq 72
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;(100+a+b*c)
        
        ;b*c
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
