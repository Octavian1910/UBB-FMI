bits 32

global _litere_mari

segment data public data use32

segment code public code use32

_litere_mari:
    push ebp
    mov ebp,esp
    
    mov esi,[ebp+8] ; sir1
    mov edi,[ebp+12] ; sir2
    
    .parcurge:
        lodsb
        cmp al,0
        je .finish
        
        cmp al,10
        je .finish
        
        cmp al,'A'
        jl .parcurge
        cmp al,'Z'
        jg .parcurge
        
        stosb
     jmp .parcurge
        
     .finish:
        mov al,0
        stosb
        
    mov esp,ebp
    pop ebp
    ret