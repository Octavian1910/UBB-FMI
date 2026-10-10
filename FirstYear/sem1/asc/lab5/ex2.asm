bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

;Se da un sir de caractere S. Sa se construiasca sirul D care sa contina toate caracterele speciale (!@#$%^&*) din sirul S
;S: '+', '4', '2', 'a', '@', '3', '$', '*'
;D: '@','$','*'

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    s db '+', '4', '2', 'a', '@', '3', '$', '*'
    lens equ $-s
    d db '!','@','#','$','%','^','&','*'
    lend equ $-d
    r times s db 0
  
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov ecx,lens ;cate elemente sunt in ecx
        mov edi,0   ; index pentru rezultat
        mov esi,s   ; incepe de la s
        
        jecxz finish:
        parcurgere_elemente_s :
            mov al,[esi]    ;valoarea elem din s
            mov edx,d       ;de unde incepe d
            mov ebx,lend    ;lungimea lui d
            parcurgere_elemente_d :
                mov ch,[edx]
                cmp al,
                dec edx
                jnz parcurgere_elemente_d
            
        
        jmp finish
        punere_elem_in_raspuns:
            
        
        finish:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
