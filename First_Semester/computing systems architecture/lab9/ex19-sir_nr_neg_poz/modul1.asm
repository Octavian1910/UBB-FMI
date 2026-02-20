bits 32

global _parsare

segment data public data use32
zece dd 10
minus dd 1

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
        
        cmp al,'-'
        jne nu_pune_minus
        mov dword[minus],-1
        jmp parcurge
        nu_pune_minus:
        cmp al,' '
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
        mul dword [minus]
        
        stosd
        
        ;contor
        inc ecx
        ;resetare
        xor edx,edx
        mov dword [minus],1
        jmp parcurge
    
    finish: ;salvam si ultimul nr
        mov eax,edx
        mul dword [minus]
        stosd
        inc ecx
    
    mov eax,ecx ;len sir
    mov esp,ebp
    pop ebp
    ret


