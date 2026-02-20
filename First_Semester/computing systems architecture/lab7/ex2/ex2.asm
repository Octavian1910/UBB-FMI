bits 32
global start

extern exit, fopen, fread, printf,fclose
import exit  msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import fclose msvcrt.dll

import printf msvcrt.dll 

; Se da un fisier text. Sa se citeasca continutul fisierului, sa se contorizeze numarul de vocale si sa se afiseze aceasta valoare. Numele fisierului text este definit in segmentul de date.

segment data use32 class=data
    nume_fisier db "input.txt",0
    mod_acces   db "r",0

    buffer      times 256 db 0   ; unde citim
    file_ptr    dd 0             ; pointer FILE*
    
    vocale db "aeiouAEIOU ",0
    len_vocale equ $-vocale
    lena dd 0
    
    rezultat dd 0
    format db "In sir sunt %d consoane "  , 0

segment code use32 class=code
start:

    ; -------------------------
    ; DESCHIDEREA FIȘIERULUI
    ; FILE * fopen(nume_fisier, mod_acces)
    ; -------------------------
    push dword mod_acces
    push dword nume_fisier
    call [fopen]
    add  esp, 4*2

    mov [file_ptr], eax      ; FILE* returnat de fopen  descriptor

    cmp eax, 0               ; dacă fopen a eșuat
    je finish


    ; -------------------------
    ; CITIREA DIN FIȘIER
    ; fread(buffer, 1, 256, file_ptr)
    ; -------------------------
    push dword [file_ptr]    ; stream
    push dword 256           ; count
    push dword 1             ; size
    push dword buffer        ; pointer buffer
    call [fread]
    add esp, 16              ; curățăm stiva

    cmp eax,0   ; in eax returneaza cate elemente sunt in buffer
    je finish
    ; acum textul din fișier este în `buffer`
    
    mov [lena],eax  ; lena= lungimea a
    
    mov ecx,[lena]
    mov esi,0
    
    loop_buffer:
        mov al,[buffer + esi]
        mov edi,0
        verif_carac :
            mov bl,[vocale + edi]
            cmp bl,0
            je contorizare ;daca a ajuns la 0 din vocale 
            
            cmp al,bl
            je final_loop_buffer
            
            inc edi
        jmp verif_carac
        
        jmp final_loop_buffer
        contorizare :
           inc dword [rezultat]
         
        final_loop_buffer : 
        inc esi 
     loop loop_buffer
          
          
       ;printf(format,rezultat)
       push dword [rezultat]
       push format
       call [printf]
       add esp,4*2    
            
        ; apelam functia fclose pentru a inchide fisierul
        ; fclose(descriptor_fis)
        push dword [file_ptr]
        call [fclose]
        add esp, 4

finish:
    push dword 0
    call [exit]
