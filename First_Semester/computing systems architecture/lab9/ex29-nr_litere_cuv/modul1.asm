bits 32


global _nr_cuvinte

segment data public data use32
lungime dd 0

segment code public code use32

_nr_cuvinte:

        push ebp
        mov ebp,esp
        
        mov esi,[ebp + 8]  ; sir
        mov edi,[ebp + 12] ;v
        xor ecx,ecx ; ct = 0
        
        .parcurge:
               lodsb
               cmp al,' '
               je .salvare
               cmp al,0
               je .finish
               
               cmp al,10
               je .finish
               
               inc ecx
               
        jmp .parcurge
        
        .salvare:
            cmp ecx,0
            je .parcurge
            mov eax,ecx
            stosd   ; incarca eax in edi  ; edi + 4
            xor ecx,ecx
            inc dword [lungime]
        jmp .parcurge
        
        
        .finish:
            cmp ecx,0
            je .finish_final
            mov eax,ecx
            stosd   ; incarca eax in edi  ; edi + 4
            inc dword [lungime]
         
       .finish_final:
            mov eax,[lungime]
        
        mov esp,ebp
        pop ebp
        ret
        