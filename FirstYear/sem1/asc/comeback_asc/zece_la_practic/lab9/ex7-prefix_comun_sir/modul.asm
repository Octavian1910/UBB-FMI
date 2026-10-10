bits 32

global _prefix

segment data public data use32
    rezultat db "",0

segment code public code use32

_prefix:

    push ebp
    mov ebp,esp
    pushad
    mov esi,[ebp+8] ;sir1
    mov edi,[ebp+12] ;sir2
    
    mov ecx,0
    repeta:
        mov al,[esi+ecx]
        mov bl,[edi+ecx]
        cmp al,0
        je finalizare_sir
        cmp bl,0
        je finalizare_sir
        
        cmp al,bl
        jne finalizare_sir
        mov [rezultat + ecx],al
        inc ecx
     jmp repeta
        
        
    finalizare_sir:
    mov byte [rezultat + ecx],0
    popad
    mov eax,rezultat
    mov esp,ebp
    pop ebp
    
    ret
    
    