bits 32


global _afisare_inversa

segment data public data use32

sir_cuvinte_inversate times 100 db 0

segment code public code use32

_afisare_inversa:

        push ebp
        mov ebp,esp
        
        cld
        mov esi,[ebp + 8]
        mov edi,[ebp + 12]
        xor ecx,ecx ; contor litere
        
        .parcurge:
            lodsb 
            
            cmp al,0
            je .finish
            
            cmp al,10 
            je .finish      
            
            cmp al,' '
            je .cuvant_invers
            
            inc ecx
            
        jmp .parcurge

        
        .cuvant_invers:
            std
            push esi
            sub esi,2
            
            .loop_interior:
                lodsb
                mov [edi],al
                inc edi
            loop .loop_interior
            
            mov al,' '
            mov [edi],al
            inc edi
            pop esi
            cld
            xor ecx,ecx
         jmp .parcurge

          
        .finish:
            std
            push esi
            sub esi,2
            
            .loop_interior2:
                lodsb
                mov [edi],al
                inc edi
            loop .loop_interior2
            
            mov al,0
            mov [edi],al
            inc edi
            pop esi
            cld
       
        mov esp,ebp
        pop ebp
        ret
        