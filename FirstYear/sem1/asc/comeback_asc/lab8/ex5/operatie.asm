bits 32
segment code use32 public code
global operatie

operatie:
        mov eax,[esp+4]
        mov ebx,[esp+8]
        mov ecx,[esp+12]
        add eax,ebx
        sub eax,ecx
        ret 12


