bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit ,fopen ,fclose,printf  ,fread              ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import fopen msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll
import fread msvcrt.dll
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    ;Se da un fisier text. Sa se citeasca continutul fisierului, sa se contorizeze numarul de caractere speciale si sa ;se afiseze aceasta valoare. Numele fisierului text este definit in segmentul de date.

    nume_fisier db "input.txt" , 0
    mod_acces db "r",0
    descriptor dd -1
    len equ 100
    text times len db 0
    len_sir dd 0
    
    caractere_speciale db "!@#$%^&*()_+"
    
    
    rezultat dd 0
    format db "%d",0
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;deschidere fisier
        ;fopen(nume_fisier,mod_acces)
        push mod_acces
        push nume_fisier
        call [fopen]
        add esp,4*2
       
        
        mov [descriptor], eax
        cmp eax,0
        je finish
        
        ;fread(text,1,len,descriptor)
        push dword [descriptor]
        push len
        push 1
        push text
        call [fread]
        add esp,4*4
        
        mov [len_sir],eax
        cmp eax,0
        je finish
        
        mov esi,0
        mov ecx,[len_sir]
        parcurgere_sir :
            mov al,[text + esi]
            mov edi,0
                parcurgere_elem_speciale:
                    mov bl,[caractere_speciale + edi]
                    cmp bl,0
                    je urm_elem_parcurgere_sir
                    
                    cmp al,bl
                    jne urm_elem
                    
                    ;daca sunt egale
                    inc dword [rezultat]
                    
                    urm_elem :
                       inc edi
                jmp parcurgere_elem_speciale
              
             urm_elem_parcurgere_sir :
                inc esi 
           loop parcurgere_sir
           
           ;printf (format,rezultat)
           push dword [rezultat]
           push format
           call [printf]
           add edi,4*2
           
           
            ;fclose(descriptor)
            push dword [descriptor]
            call [fclose]
           
           
                
            
            
        
        
    
        finish:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
