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

    s DB 01011100b, 10001001b, 11100101b 
    lens equ $-s
    
    raspuns times lens db 0
 
    ;d DB 10100111b, 10010001b, 00111010b
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov ecx, lens     ; cate caractere avem
        mov esi, s + lens - 1 ;  ; sursa
        mov edi, raspuns        ; destinatia

        repeta:
        mov al, [esi]
        call oglindeste
        mov [edi], bl

        dec esi               
        inc edi            
        loop repeta
        jmp finish
        oglindeste:
            push ecx
            mov bl, 0    ; rezultatul      
            mov cl, 8      ;tot cate 8 octeti      
            bucla:
                shl bl, 1      ;facem loc pt noul bit
                shr al, 1      ;extragem bitul din dreapta in CF
                adc bl, 0      ;adunam bitul pe pozitia alocata
                dec cl         ;scadem 1 octet
                jnz bucla
                pop ecx 
                ret
           
        finish:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
        