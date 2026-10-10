bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

                          segment data ... Varianta 1


MOV ECX, ls
MOV ESI, 0
MOV EDI, 0
JECXZ final
repeta:
MOV AX, [s+ESI]
MOV [d+EDI], AX
add ESI, 2
add EDI, 2
LOOP repeta
final:
                          
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    s dw 1234h, 5678h
    ls equ ($-s)/2  ;nr de cuvinte
    d times ls dw 0
; our code starts here
segment code use32 class=code
    start:
        mov ecx,ls
        mov esi,0
        mov edi,0
        jecxz final
        repeta:
            mov ax,[s+esi]
            mov [d+edi],ax
            add esi,2
            add edi,2
        loop repeta
        
        final:
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
