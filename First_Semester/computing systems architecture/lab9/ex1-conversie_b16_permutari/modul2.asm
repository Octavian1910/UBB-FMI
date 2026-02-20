bits 32 

global _permutari
extern _printf

segment data public data use32

numar dd 0
format db "%x",13,10,0
segment code public code use32

_permutari:
    push ebp
    mov ebp,esp
    xor edx,edx
 
    mov eax,[ebp + 8] ;sir1
    mov [numar],eax
    mov ecx,7
    parcurge:
        pushad
        rol dword [numar],4
        push dword [numar]
        push format
        call _printf
        add esp,4*2
        popad

   loop parcurge
        
    finish:
    mov eax,edx
    mov esp,ebp
    pop ebp
    ret
    
    
    
    
    
    
    