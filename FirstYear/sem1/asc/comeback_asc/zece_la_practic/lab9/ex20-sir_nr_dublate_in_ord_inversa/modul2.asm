bits 32

global _intoarce_si_dubleaza

segment data public data use32
doi dd 2
patru dd 4

segment code public code use32

_intoarce_si_dubleaza:
    push ebp
    mov ebp,esp
    pushad
    mov esi,[ebp+8] ; v
    mov edi,[ebp+12] ; rez
    mov eax,[ebp+16] ;len
    mov ecx,[ebp+16] ;len

    mul dword [patru]
    sub eax,4
    add esi,eax  ; mergem la finalul sirului
    std          ;mergem de la dreapta la stanga
    
    .parcurge:
        lodsd
        mul dword [doi] ;eax = eax*2
        mov [edi],eax
        add edi,4
    loop .parcurge   ;de ecx=len ori
    
    cld
    popad
    mov esp,ebp
    pop ebp
    ret


