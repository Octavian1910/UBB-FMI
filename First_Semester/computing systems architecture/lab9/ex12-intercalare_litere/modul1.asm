bits 32

global _intercalare


segment data public data use32
rezultat times 100 db 0

segment code public code use32


_intercalare:

    push ebp
    mov ebp,esp
    
    mov ebx,[ebp + 8]   ;sir1
    mov edx,[ebp + 12]  ;sir2
    mov edi,[ebp + 16]  ;sir3
    xor ecx,ecx
    parcurge:
        cmp al,0
        je finish
        mov al,[ebx+ecx];
        stosb
        mov al,[edx+ecx];
        stosb
        inc ecx
    jmp parcurge
    
    finish:
        mov al,0
        stosb
   
     mov esp,ebp
     pop ebp
     ret

        
        
    