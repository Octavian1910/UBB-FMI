bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, printf,fclose,fread,fopen               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

import printf msvcrt.dll
import fclose msvcrt.dll
import fread msvcrt.dll
import fopen msvcrt.dll
                          
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...

    ; Se da un fisier text. Sa se citeasca continutul fisierului, sa se determine cifra cu cea mai mare frecventa si sa se afiseze acea cifra impreuna cu frecventa acesteia. Numele fisierului text este definit in segmentul de date.
    nume_fisier db "input.txt",0
    mod_acces db "r",0
    ;        9 8 7 6 5 4 3 2 1 0
    frecv db 0,0,0,0,0,0,0,0,0,0
    len equ 100
    descriptor dd -1
    text times len db 0
    nr_elem dd 0
    
    max_cifra dd 0
    max_frecv_cifra db 0
    format db "Cifra %d apare de %d ori ", 0
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        
        mov [nr_elem],eax
        cmp eax,0
        je finish
        
        
        mov esi,0
        mov ecx,[nr_elem]
        parcurgere_text:
            mov al,[text + esi]
            sub al,'0'
            movzx edi,al
            add byte [frecv+edi],1
            inc esi
        loop parcurgere_text
        
        
        mov ecx,10
        mov esi,0
        gasire_cifra_frecv_max:
            mov al,[frecv + esi] ;frecventa cifrei curente
            
            cmp al,[max_frecv_cifra]
            jb urm

            ;daca e mai mare frecv actualizam
            mov [max_frecv_cifra],al
            mov [max_cifra],esi
            
            urm : 
              inc esi
         loop gasire_cifra_frecv_max
         
         
         movzx eax , byte [max_frecv_cifra]
         ;printf(format,cifra,frecv)
         push eax ; max_frecv_cifra
         push dword [max_cifra]
         push format
         call [printf]
         add esp,4*3
         
         ;fclose
         push dword [descriptor]
         call [fclose]
         add esp , 4*1
         
         
         
            
            
        
        finish:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
