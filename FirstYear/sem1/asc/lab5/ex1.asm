bits 32 ; assembling for the 32 bits architecture


;Se da un sir de octeti S de lungime l. Sa se construiasca sirul D de lungime l-1 astfel incat elementele din D sa reprezinte ;produsul dintre fiecare 2 elemente consecutive S(i) si S(i+1) din S.

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    s db 1, 2, 3, 4 ;va trebui sa obtinem d db 2, 6, 12
    lens equ $-s
    d times lens dw 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov ecx,lens - 1; ; cate elemente vom avea in d
        mov esi,s ;index s
        mov edi,0 ;index d
        prodS:
            mov al,[esi]  ;mutam in al offsetul locatiei elem curent din s
            inc esi       ;trecem la urm elem
            mov bl,[esi]    ;il punem in bl
            mul bl              ;ax = s[ind]*s[ind+1]
            mov [d + edi],ax            ;mutam in d rezultatul
            add edi,2           ;trb sa crestem tot cu cate 2 octeti
            loop prodS          ;scadem ecx
            
            
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
