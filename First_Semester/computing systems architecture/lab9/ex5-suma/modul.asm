bits 32
global _calcul

segment data public data use32

segment code public code use32

_calcul:
    push ebp
    mov ebp, esp

    mov eax, [ebp + 8]    ; a
    add eax, [ebp + 12]   ; + b
    sub eax, [ebp + 16]   ; - c

    mov esp, ebp
    pop ebp
    ret
