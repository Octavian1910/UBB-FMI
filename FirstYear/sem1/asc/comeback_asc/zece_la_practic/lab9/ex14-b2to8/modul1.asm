bits 32

global _salvare

segment data public data use32
segment code public code use32

_salvare:
    push ebp
    mov ebp,esp
    
    mov esi,[ebp+8] ;sir
    mov edi,[ebp+12]    ;v
    
    xor edx,edx ;temp
    xor ecx,ecx ;len
    parcurge:
        lodsb
        cmp al,0
        je finish
        
        cmp al,10
        je finish
        
        cmp al,' '
        je salvare
        
        ;e cifra
        cmp al,'0'
        je e_zero
        
        ;daca nu este 1
        shl edx,1
        add edx,1
        jmp parcurge
        
        e_zero:
        shl edx,1
        add edx,0

    jmp parcurge
        
        
    salvare:
        mov eax,edx
        stosd
        xor edx,edx
        inc ecx
    jmp parcurge
        
    finish:
        mov eax,edx
        stosd
        xor edx,edx
        inc ecx
    mov eax,ecx ;returnam ecx
    mov esp,ebp
    pop ebp
    ret