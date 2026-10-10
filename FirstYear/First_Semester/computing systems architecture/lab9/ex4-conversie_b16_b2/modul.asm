bits 32

global _parsare
extern _printf
segment data public data use32

zece dd 10
lungime dd 0

segment code public code use32


_parsare:
    push ebp
    mov ebp,esp
    
    mov esi,[ebp + 8]
    mov edi,[ebp + 12]
    xor edx,edx
    
    parcurgere:
        lodsb
        
        cmp al,0
        je finish
        
        cmp al,10  ;pt caracterul nul
        je finish
        
        cmp al,' '
        je salvare
        mov cl,al   ;cl = uc
        mov eax,edx ;edx are nr curent
        mul dword [zece] ;eax *10
        sub cl,'0'  
        movzx ecx,cl
        add eax,ecx ;eax*10+uc
        mov edx,eax
    jmp parcurgere
    
    salvare:
        mov [edi],edx
        add edi,4
        inc dword [lungime]
        xor edx,edx
    jmp parcurgere
        
        
    finish:
        mov [edi],edx
        add edi,4
        inc dword [lungime]
        mov eax,[lungime]
        

     mov esp,ebp
     pop ebp
     ret
