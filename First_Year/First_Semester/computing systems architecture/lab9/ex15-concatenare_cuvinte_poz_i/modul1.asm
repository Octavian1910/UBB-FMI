bits 32

global _cuvant_cerut
extern _printf

segment data public data use32
format db "%c",0


segment code public code use32


_cuvant_cerut:

    push ebp
    mov ebp,esp
    mov ebx,0  ;contor spatii
    
    mov esi,[ebp + 8]
    
    mov ecx,[ebp + 12]
    
    mov edi,[ebp + 16]
    parcurgere:
    
        cmp ebx,ecx
        je creare_cuvant
        lodsb
        cmp al,' '
        jne nu_incrementa
        inc ebx
        
        nu_incrementa:
        
    jmp parcurgere
    
    
    creare_cuvant:
        lodsb 
        cmp al,' '
        je finish
        cmp al,0
        je finish
        cmp al,10
        je finish
        stosb
        
     jmp creare_cuvant
        
    
     finish:
     mov al,0
     stosb
     mov esp,ebp
     pop ebp
     ret

        
        
    