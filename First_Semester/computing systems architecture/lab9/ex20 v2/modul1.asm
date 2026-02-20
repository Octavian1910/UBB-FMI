bits 32

global _parsare

segment data public data use32
zece dd 10

segment code public code use32

_parsare:
    push ebp
    mov ebp,esp
    xor ecx,ecx
    xor edx,edx
    
    mov esi,[ebp+8]
    mov edi,[ebp+12]
    parcurge:
        lodsb
        cmp al,10
        je finish
        cmp al,0
        je finish
        cmp al,','
        je salvare
        
        ;construire nr
        mov bl,al   ;salvam uc
        sub bl,'0'
        movzx ebx,bl
        mov eax,edx
        mul dword [zece] ;eax = eax*10
        add eax,ebx ;eax = eax*10 + uc
        mov edx,eax     ;in edx tinem minte rezultatul
        
    jmp parcurge
    
    salvare:
        mov eax,edx
        stosd
        inc ecx
        xor edx,edx
        jmp parcurge
    
    finish: ;salvam si ultimul nr
        mov eax,edx
        stosd
        inc ecx
    
    mov eax,ecx ;len sir
    mov esp,ebp
    pop ebp
    ret


