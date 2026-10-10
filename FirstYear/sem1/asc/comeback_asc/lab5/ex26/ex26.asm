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
    
    s db 1, 4, 2, 3, 8, 4, 9, 5
    lens equ $-s
    max_poz_pare db -128        ; cel mai mic
    min_poz_impare db 127       ; cel mai mare

    
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        ;0 daca nu e 0
        ;1 daca e 0
        
        mov esi , 0
        mov ecx,lens
        loops :
            mov al,[s+esi]
            test esi,1 ; daca al impar => zero flag = 0 , rez != 0
            jnz e_impar
            
            ;e par
            cmp al,[max_poz_pare]
            jle final_loop ; nu trb actualizat\
            
            ;trb actualizat
            mov [max_poz_pare],al
            jmp final_loop
               
     
            ;e impar
            e_impar:
                cmp al,[min_poz_impare]
                jae final_loop ; nu trb actualizat

                 ;daca trb actualizat
                 mov [min_poz_impare],al

                    
               final_loop :
                inc esi
         loop loops
                
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
