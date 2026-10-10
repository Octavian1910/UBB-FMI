bits 32

global _baza2
extern _printf
segment data public data use32
rezultat times 100 db 0
doi dd 2


segment code public code use32


_baza2:
    push ebp
    mov ebp,esp
    cld
    
    mov edi,rezultat
    
    mov eax,[ebp+8]
    xor ecx,ecx ; contor cifre adaugate in stiva
    
    pregatire_stiva:
        cmp eax,0
        je creare_sir
        inc ecx
        xor edx,edx
        div dword [doi] ;eax = cat edx = rest
        add edx,'0'
        push edx
    jmp pregatire_stiva
    
   
    creare_sir:
        pop eax
        stosb
    loop creare_sir
     
     mov eax,rezultat
     mov esp,ebp
     pop ebp
     ret
