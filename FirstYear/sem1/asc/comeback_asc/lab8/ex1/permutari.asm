bits 32
segment code use32 public code
global permutari
extern printf

permutari:
    mov esi,[esp + 4]
    mov eax,[esp + 8]
    
    mov ecx,7
    repeta:
        rol eax,4
        pushad
        push dword eax
        push dword esi
        call [printf]
        add esp, 4*2
        popad 
    loop repeta
    
    ret 8