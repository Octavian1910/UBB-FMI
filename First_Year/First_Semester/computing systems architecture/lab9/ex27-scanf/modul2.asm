bits 32


global _impare

segment data public data use32
lungime dd 0
doi dd 2

segment code public code use32

_impare:

        push ebp
        mov ebp,esp
        mov dword [lungime],0
        mov esi,[ebp + 8]  ; v
        mov edi,[ebp + 12] ; pare
        mov ecx,[ebp + 16]  ; n
        .parcurge:
            lodsd
            mov ebx,eax
            xor edx,edx
            div dword [doi]
            cmp edx,0
            jne .salveaza
            .sub_salveaza:
        
        loop .parcurge
        
        jmp finish
        
        .salveaza:
            mov eax,ebx
            inc dword [lungime]
            stosd
        jmp .sub_salveaza
        
        finish:
        mov eax,[lungime]
        mov esp,ebp
        pop ebp
        ret
        