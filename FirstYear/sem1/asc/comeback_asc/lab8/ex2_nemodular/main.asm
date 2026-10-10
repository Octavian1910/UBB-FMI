bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,gets,printf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

import gets msvcrt.dll
import printf msvcrt.dll
                          
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    buffer resb 100
    rezultat resd 100
    format db "%d ",0
    

; our code starts here
segment code use32 class=code
    start:
        ; ...
        push buffer
        call [gets]
        add esp,4
        
        mov esi,buffer
        mov edi,rezultat
        
        ;ebx - folosit pt semn
        ;eax - folosit pt a incarca caracterul curent
        ;edx - nr curent
        ;ecx - contor de numere
        xor ecx,ecx
        
        parsare:
            ;skip_spatii
            skip_spatii:
                lodsb
                cmp al,0
                je terminare_parsare
                cmp al,' '
                je skip_spatii
                
            ;verificare_semn
            xor ebx,ebx
            mov ebx,1
            
            cmp al,'-'
            jne e_pozitiv
            mov ebx,-1
            lodsb  ; daca e negativ trecem de minus
            
            e_pozitiv:
            ;incepem conversia
            xor edx,edx  ; edx = 0 ca sa salvam numarul curent
            convert_digit:
                cmp al,'0'
                jb terminare_numar
                cmp al,'9'
                ja terminare_numar
                
                sub al,'0' ;convertim la cifra
                push eax
                mov eax,10
                mul edx 
                mov edx,eax
                pop eax
                movzx eax,al
                add edx,eax  ; o punem
                lodsb
                jmp convert_digit
                
            terminare_numar:
            ;ii aplicam semnul
            imul edx,ebx
            
            stocare_numar:
            inc ecx
            mov [edi],edx
            add edi,4
            cmp al,0
            jne parsare     ;daca e diferit de caracterul nul mergem mai departe
           
           terminare_parsare:
            

           mov esi,rezultat
           loop_afisare:
            lodsd
            ;printf(format,numar)
            push ecx
            push eax
            push format
            call [printf]
            add esp,4*2
            pop ecx
            loop loop_afisare
            
            
        finish:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
