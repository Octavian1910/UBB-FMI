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
a1 db 2, 4, 6, 8
a2 dw 2, 4, 6, 8
a3 dd 2, 4, 6, 8
a4 db '2', '4', '6', '8'
a5 db 24h, 68h
a6 dw 24h, 68h
a7 dd 24h, 68h
a8 db '24', '68'
a9 dw '24', '68'
a10 dw '2', '4', '6', '8'
a11 db 2468h
a12 dw 2468h
a13 dd 2468h
a14 dd 02040608h, 01030507h
; our code starts here
segment code use32 class=code
    start:
        ; ...
    mov ax,[a9]
    mov bx,'24'
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
