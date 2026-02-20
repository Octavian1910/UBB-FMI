bits 32

global _concatenare

segment data public data use32
    rezultat db "",0

segment code public code use32

_concatenare:

    push ebp
    mov ebp,esp
    
    mov esi,[ebp + 8]
    mov edi,rezultat
    sir_1:
        lodsb
        cmp al,0
        je terminare_sir1
        cmp al,10
        je terminare_sir1
        stosb
    jmp sir_1
    
    
    terminare_sir1:
    
    mov esi,[ebp + 12]
    sir_2:
        lodsb
        cmp al,0
        je terminare_sir2
        cmp al,10
        je terminare_sir2
        stosb
    jmp sir_2
    
    terminare_sir2:
    mov al,0
    stosb
    mov eax,rezultat
    
    mov esp,ebp
    pop ebp
    
    ret
    
    