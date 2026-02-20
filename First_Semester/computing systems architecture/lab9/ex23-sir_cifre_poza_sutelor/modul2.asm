bits 32

global _sute

segment data public data use32

suta dd 100
zece dd 10

segment code public code use32

_sute:
    push ebp
    mov ebp,esp
    
    mov eax,[ebp + 8]
    
    xor edx,edx
    div dword [suta]
    xor edx,edx
    div dword [zece]
    
    mov eax,edx
    mov esp,ebp
    pop ebp
    ret