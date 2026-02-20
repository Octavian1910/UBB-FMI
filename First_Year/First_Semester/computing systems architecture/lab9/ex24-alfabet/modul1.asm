bits 32


global _inlocuire

segment data public data use32
lungime dd 0

segment code public code use32

_inlocuire:

        push ebp
        mov ebp,esp
        
        cld
        mov ebx,[ebp + 8]  ; alfabet
        mov esi,[ebp + 12] ; sir2
        mov edi,[ebp + 16] ; sir2
        
        .parcurge:
            lodsb
            cmp al,10
            je .finish
            
            cmp al,0
            je .finish
            
            sub al,'a'
            movzx eax,al
            mov al, [ebx + eax]
            stosb
         jmp .parcurge
            
            
        .finish:
        mov al,0
        stosb
        
        mov esp,ebp
        pop ebp
        ret
        