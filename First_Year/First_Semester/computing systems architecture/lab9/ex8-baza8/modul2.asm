bits 32

global _cod_asci

segment data public data use32

segment code public code use32


_cod_asci:

    push ebp
    mov ebp,esp
    
    mov eax,[ebp+8]
    add eax,"0"
    
    mov esp,ebp
    pop ebp
    ret

