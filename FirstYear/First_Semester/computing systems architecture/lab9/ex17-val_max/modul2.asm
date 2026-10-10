bits 32

global _val_minima

segment data public data use32

segment code public code use32


_val_minima:

    push ebp
    mov ebp,esp
    
    mov esi,[ebp+8] ; v
    mov ecx,[ebp+12] ; len
    lodsd
    mov edx,eax ; in eax e primul element
    dec ecx
    .parcurge:
        
        lodsd
        cmp eax,edx
        jl .nu_e_maxim
        ;daca e maxim
        mov edx,eax
        
        .nu_e_maxim:
    loop .parcurge
        
        

    mov eax,edx
    mov esp,ebp
    pop ebp
    ret

