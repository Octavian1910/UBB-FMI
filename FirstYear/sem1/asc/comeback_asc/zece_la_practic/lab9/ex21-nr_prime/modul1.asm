bits 32


global _parsare

segment data public data use32
lungime dd 0
zece dd 10

segment code public code use32

_parsare:

        push ebp
        mov ebp,esp
        
        cld
        mov esi,[ebp + 8]  ; sir
        mov edi,[ebp + 12] ; v
        xor ecx,ecx
        xor edx,edx
        
        .parcurge:
            lodsb
            cmp al,0
            je .finish
            cmp al,10
            je .finish
            
            cmp al,' '
            je .salvare

            ;e cifra
            mov bl,al  ; uc
            sub bl,'0'
            movzx ebx,bl
           
            mov eax,edx
            mul dword [zece] ; eax= eax*10
            add eax,ebx  ; eax= eax*10 + uc
            mov edx,eax
        jmp .parcurge
        
        .salvare:
            mov eax,edx
            inc ecx
            xor edx,edx
            stosd
        jmp .parcurge
        
        .finish:
            mov eax,edx
            inc ecx
            stosd
        
        mov eax,ecx  ;eax = lungime
        mov esp,ebp
        pop ebp
        ret
        