bits 32
global _e_subsecventa

segment code public code use32
_e_subsecventa:
    push ebp
    mov ebp, esp
    push esi
    push edi
    push ebx
    
    mov edi, [ebp+8]     ; sir1
    mov esi, [ebp+12]    ; sir2
    
.parcurge:
    lodsb                ; AL = sir2[i], ESI++
    
    cmp al, 0
    je .nu_gasit
    cmp al, 10
    je .nu_gasit
    
    ; Compară cu primul caracter din sir1
    cmp al, [edi]
    jne .parcurge
    
    ; Match găsit - verifică restul
    dec esi             
    push esi             ; ✅ Salvează poziția
    xor ecx, ecx
    
.verifica:
    mov al, [esi + ecx]  ; sir2[poziție + offset]
    mov bl, [edi + ecx]  ; sir1[offset]
    
    ; Am terminat sir1? SUCCESS!
    cmp bl, 0
    je .gasit
    cmp bl, 10
    je .gasit
    
    ; Am terminat sir2? FAIL
    cmp al, 0
    je .nu_match
    cmp al, 10
    je .nu_match
    
    ; Compară caractere
    cmp al, bl
    jne .nu_match
    
    inc ecx
    jmp .verifica
    
.nu_match:
    pop esi              ; Restaurează poziția
    inc esi              ; Avansează cu 1
    jmp .parcurge
    
.gasit:
    pop esi              ; Curăță stiva
    mov eax, 1
    jmp .finish
    
.nu_gasit:
    mov eax, 0
    
.finish:
    pop ebx
    pop edi
    pop esi
    pop ebp
    ret