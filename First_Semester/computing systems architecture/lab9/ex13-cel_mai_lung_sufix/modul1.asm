bits 32

global _sufix
extern _printf

segment data public data use32
rezultat times 100 db 0

segment code public code use32


_sufix:

    push ebp
    mov ebp,esp
    mov ebx,0  ;contor spatii
    
    mov esi,[ebp + 8]
    mov edi,[ebp + 12]
    
    cld
    .parcurge_sir1:
        lodsb
        cmp al,0
        je .sub_parcurge_sir1
    jmp .parcurge_sir1
    
    .sub_parcurge_sir1:
    mov ebx,esi         ;unde se termina sir1
    add ebx,2
    
    mov esi,[ebp + 12]
    .parcurge_sir2:
        lodsb
        cmp al,0
        je .sub_parcurge_sir2
    jmp .parcurge_sir2
    
     .sub_parcurge_sir2:
     sub esi,2  ;sir 2
     mov edi,ebx  ; sir 1
     std
     .compara_sirurile:
        cmpsb
        jne .sub_compara_sirurile
        cmp esi,0
        je .sub_compara_sirurile
     jmp .compara_sirurile
     
     .sub_compara_sirurile:
     cld
     add esi,2
     mov edi,rezultat
     .pune_in_rezultat:
        lodsb
        cmp al,0
        je finish
        stosb
     
    
     finish:
     stosb
     mov eax,rezultat
     mov esp,ebp
     pop ebp
     ret

        
        
    