bits 32

global _parsare

segment data public data use32
zece dd 10


segment code public code use32


_parsare:

    push ebp
    mov ebp,esp
    
    mov esi,[ebp + 8]
    mov edi,[ebp + 12]
    xor edx,edx
    xor ecx,ecx
    
    .parcurge:
        lodsb
        cmp al,0
        je .finish
        cmp al,10
        je .finish
        
        cmp al,' '
        je .salvare
        
        ;daca nu e cifra si formam numarul
        sub al,'0'
        movzx ebx,al ;ebx = uc
        mov eax,edx
        mul dword [zece]    ;eax = eax * 10
        add eax,ebx         ;eax = eax * 10 + uc
        mov edx,eax ;salvam in edx numarul
        jmp .parcurge
        
      .salvare:
        mov eax,edx
        stosd
        xor edx,edx
        inc ecx ;ct de numere
      jmp .parcurge
      
    .finish:
        mov eax,edx
        stosd
        xor edx,edx
        inc ecx ;ct de numere
    
    mov eax,ecx ;salvam ct de numere
    mov esp,ebp
    pop ebp
    ret

        
        
    