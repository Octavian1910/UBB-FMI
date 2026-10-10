bits 32
segment code use32 public code
global modul

extern printf

segment data use32 class=data
    format db "%x",13,10,0
    


modul:
    mov ecx,7
    mov eax,[esp + 4]
    repeta:
        ror eax,4
        pushad
        push dword eax
        push format
        call [printf]
        add esp,4*2
        popad
        
    loop repeta
        
    
    ret 4