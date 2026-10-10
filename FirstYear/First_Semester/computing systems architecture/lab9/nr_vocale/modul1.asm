bits 32


global _litere_mici

segment data public data use32
lungime dd 0

segment code public code use32

_litere_mici:

        push ebp
        mov ebp,esp
        
        mov esi,[ebp + 8]  ; sir1
        mov edi,[ebp + 12] ; sir2
        
        .parcurge:
            lodsb
            cmp al,0
            je .finish
            cmp al,10
            je .finish
            
            cmp al,'a'
            jl .nu_e_bun
            cmp al,'z'
            jg .nu_e_bun
            
            ;ebun
            stosb
            .nu_e_bun:
              
        jmp .parcurge
        
        .finish:
        mov al,0
        stosd
        
        
        mov esp,ebp
        pop ebp
        ret
        