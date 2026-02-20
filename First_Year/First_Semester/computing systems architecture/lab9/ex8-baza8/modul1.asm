bits 32

global _baza8

segment data public data use32
zece dd 10
opt dd 8


segment code public code use32


_baza8:

    push ebp
    mov ebp,esp
    mov ecx,0
    
    mov eax,[ebp + 8]
    
    impartire:
        cmp eax,0
        je compunere_nr
        xor edx,edx
        div dword [opt] ; eax = cat ; edx = rest
        push edx
        mov ebx,eax  ; ebx = cat
        inc ecx ;ct pt cifre bagate in stiva
     jmp impartire
     
     compunere_nr:
        pop ebx
        mul dword [zece] ; eax= eax*10
        add eax,ebx
     loop compunere_nr
     
     
     mov esp,ebp
     pop ebp
     ret

        
        
    