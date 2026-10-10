bits 32


global _val_max

segment data public data use32
lungime dd 0

segment code public code use32

_val_max:

        push ebp
        mov ebp,esp
        
        mov esi,[ebp + 8] ;vector
        mov ecx,[ebp + 12] ;len
        
        lodsd
        mov ebx,eax ;ebx = primul nr
        sub ecx,1
        parcurge:
            lodsd
            cmp ebx,eax
            jnl nu_e_max
            
            mov ebx,eax
            
            nu_e_max:
            
       loop parcurge
       
       
        mov eax,ebx
        mov esp,ebp
        pop ebp
        ret
        