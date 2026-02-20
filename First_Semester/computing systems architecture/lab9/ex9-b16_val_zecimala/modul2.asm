bits 32

global _afisare

extern _printf

segment data public data use32
format db "Nr : %x este  %u si %d ",13,10,0

segment code public code use32

_afisare:
    push ebp
    mov ebp,esp
    mov eax,[ebp + 8]
    
    push eax
    push eax
    push eax
    push format
    call _printf
    add esp,4*2

    mov esp,ebp
    pop ebp
    ret    

