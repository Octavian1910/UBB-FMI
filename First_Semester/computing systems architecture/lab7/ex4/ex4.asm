bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,fopen  ,fclose , printf ,fread            ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific function\s
import fopen msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll
import fread msvcrt.dll
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
; Se da un fisier text. Sa se citeasca continutul fisierului, sa se contorizeze numarul de cifre pare si sa se afiseze aceasta valoare. Numele fisierului text este definit in segmentul de date.

    nume_fisier db "input.txt",0
    mod_acces db "r",0
    len equ 100
    text times len db 0
    descriptor dd -1
    
    len_text dd 0
    rezultat dd 0
    format db "%d",0
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        ;deschidere fisier
        ;fopen (nume_fisier,mod_acces)
         push mod_acces
         push nume_fisier
         call [fopen]
         add esp ,4*2
         
         mov [descriptor],eax
         cmp eax,0
         je finish ;nu a mers citirea
         
         ; citim textul in fisierul deschis folosind functia fread
         ; eax = fread(text, 1, len, descriptor_fis)
         
         push dword [descriptor]
         push len
         push 1
         push text
         call [fread]
         add esp,4*4
         
         ;in eax avem nr de caractere cittie
         
         mov [len_text],eax
         
         mov ecx,[len_text]
         mov esi,0 
         
         loop_text : 
            mov al,[text + esi]
            sub al,"0"

            cmp al,0
            jb final_loop_text
            
            cmp al,9
            ja final_loop_text
            
            test al,1
            jz final_loop_text ; nu trb contorizat e par
        
            inc dword [rezultat] ;inseamna ca e impar
            
            final_loop_text :
            inc esi
         loop loop_text
         
         
         ;printf(format,valoare)
         
         push dword [rezultat]
         push format
         call [printf]
         add esp,4*2
         
     
         ;pt a inchide fisierul 
         ;fclose(descriptor)
         push dword [descriptor]
         call [fclose]
         add esp,4*1
         
         
        finish:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
