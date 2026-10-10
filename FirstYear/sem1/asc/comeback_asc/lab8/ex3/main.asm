bits 32 ; assembling for the 32 bits architecture


; Se dau doua siruri continand caractere. Sa se calculeze si sa se afiseze rezultatul concatenarii tuturor caracterelor tip cifra zecimala din cel de-al doilea sir dupa cele din primul sir si invers, rezultatul concatenarii primului sir dupa al doilea.

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

extern concatenari
                          
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    sir1 db "abcd1234asd",0
    sir2 db "cdb5678asd9",0
    

; our code starts here
segment code use32 class=code
    start:
        ;concaternari(sir1,sir2)
        push dword sir2
        push dword sir1
        call concatenari ;ret 4*2
        
        ;concaternari(sir2,sir1)
        push dword sir1
        push dword sir2
        call concatenari ;ret 4*2
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
