bits 32


global _e_nr_prim

segment data public data use32
lungime dd 0
numar dd 0
doi dd 2

segment code public code use32

_e_nr_prim:

        push ebp
        mov ebp,esp
        
        mov eax,[ebp+8]
        mov [numar],eax
        
        cmp dword [numar],1
        jle nu_e_prim
        
        cmp dword [numar],2
        je e_prim
        
        xor edx,edx
        div dword [doi]  ; eax = cat edx = rest
        cmp edx,0
        je nu_e_prim  ; e nr par
        
        mov ecx,eax   ; n/2
        xor edx,edx
        parcurge:
            cmp ecx,1
            jle e_prim
        
            mov eax,[numar]
            xor edx,edx
            div ecx
            cmp edx,0
            je nu_e_prim
       loop parcurge
            
       
       nu_e_prim:
            mov eax,0
            jmp finish
            
       e_prim:
        mov eax,1
        
        
        finish:
        
        mov esp,ebp
        pop ebp
        ret
        