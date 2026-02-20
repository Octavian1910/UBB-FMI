bits 32

global _VERIFICA

segment data public data use32
segment code public code use32

_VERIFICA:
    push ebp
    mov ebp,esp
    cld
    mov esi,[ebp+8];sir
    mov ebx,[ebp+12];caracter
    xor eax,eax  ; eax = 0 , 1 daca apare 0 altfel
    parcurge:
        lodsb
        cmp al,10  ;\n
        je finish
        cmp al,0   ;\0
        je finish
        
        movzx eax,al
        cmp eax,ebx
        je apare
        
    jmp parcurge
    
    apare:
        mov eax,1
    
    finish:
    
    
    mov esp,ebp
    pop ebp
    ret
    


