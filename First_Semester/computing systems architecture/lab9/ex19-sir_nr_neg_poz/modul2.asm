bits 32

global _pozitive

segment data public data use32


segment code public code use32

_pozitive:
    push ebp
    mov ebp,esp
    
    cld 
    
    mov esi,[ebp+8] ; v
    mov edi,[ebp+12] ; rez
    mov ecx,[ebp+16] ; len
    xor edx,edx
    
    parcurge:
        lodsd   ;!distruge eax
        cmp eax,0
        jl e_negativ ;greater and lower pt semn
        
        e_pozitiv:
            inc edx
            stosd
        e_negativ:
     loop parcurge
   
    ;in eax este lungimea vectorului rezultat
    mov eax,edx
    mov esp,ebp
    pop ebp
    ret


