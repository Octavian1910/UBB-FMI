bits 32

global _asmUpper

segment data public data use32
    lenRez dd 0
    adresaSirRezultat dd 0
    adresaSirParam dd 0
    
segment code public code use32

_asmUpper:
    push ebp
    mov ebp,esp
    
    ;lenStrUpp=asmUpper(lenStrRez,strRez,strUpp);
    mov eax,[ebp+8]
    mov [lenRez],eax
    
    mov eax,[ebp+12]
    mov [adresaSirRezultat],eax
    
    mov eax,[ebp+16]
    mov [adresaSirParam],eax
    
    
    mov edi,[adresaSirRezultat]
    mov esi,[adresaSirParam]
    mov ecx,[lenRez]
    
    jecxz final
    
    rp:
        lodsb
        cmp al,'a'
        jb next
        cmp al,'z'
        jg next
        sub al,'a'-'A'
        next:
            stosb
            inc dword [lenRez]
    loop rp
    
    final:
        mov eax,[lenRez]
        mov esp,ebp
        pop ebp
        ret
    
    
    