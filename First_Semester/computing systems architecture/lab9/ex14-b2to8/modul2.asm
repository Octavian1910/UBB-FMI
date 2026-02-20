bits 32

global _conversie_baza_8
extern _printf

segment data public data use32
opt dd 8
sir times 100 db 0
format db "%s",0
format_zero db "%d",0
segment code public code use32

_conversie_baza_8:
    push ebp
    mov ebp,esp
    
    mov eax,[ebp+8] ;nr
    cmp eax,0
    je e_zero
    
    xor ecx,ecx
    mov edi,sir
    xor edx,edx
    
    parcurge:
        cmp eax,0
        je afisare
        xor edx,edx
        div dword [opt]
        inc ecx
        push edx
     jmp parcurge
     

     
     afisare:   
        pop eax
        add eax,'0'
        stosb
     loop afisare
     
     mov al,0
     stosb
     
     push sir
     push format
     call _printf
     add esp,4*2
   
    jmp finish
    e_zero:
    push dword 0
    push format_zero
    call _printf
    
    finish:
    
    mov esp,ebp
    pop ebp
    ret