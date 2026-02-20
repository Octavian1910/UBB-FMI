bits 32

global _parsare

segment data public data use32
zece dd 10
segment code public code use32

_parsare:
    push ebp
    mov ebp,esp
    
    mov esi,[ebp + 8]   ;char
    mov edi,[ebp + 12]  ;v
    xor ecx,ecx
    xor edx,edx
    
    parcurge:
        lodsb
        cmp al,10
        je salveaza
        cmp al,','
        je salveaza
        
        ;e cifra
        mov bl,al
        sub bl,'0'
        movzx ebx,bl
        mov eax,edx
        mul dword [zece]
        add eax,ebx
        mov edx,eax
        
     jmp parcurge
     
     
     salveaza:
            mov bl,al ;pt finish
            mov eax,edx
            stosd
            xor edx,edx
            inc ecx
            
            cmp bl,10
            je finish
     jmp parcurge
     
     
            
        
        
    finish:
    mov eax,ecx
    
    mov esp,ebp
    pop ebp
    ret
