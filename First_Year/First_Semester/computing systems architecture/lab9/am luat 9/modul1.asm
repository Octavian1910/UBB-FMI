bits 32

global _OGLINDIT

extern _printf

segment data public data use32
doi dd 2
format db "%s",13,10,0
format2 db "%c",0
segment code public code use32

_OGLINDIT:
    push ebp
    mov ebp,esp
    cld
    mov esi,[ebp+8];sir
    xor ecx,ecx  ;ct litere
    
    .parcurge:
        lodsb
        cmp al,0
        je .cuv_numarate
        cmp al,10
        je .cuv_numarate
        
        inc ecx
        
    jmp .parcurge
    
    .cuv_numarate:
    push esi        ;salvam finalul sirului
    xor edx,edx
    xor eax,eax
    mov eax,ecx
    div dword [doi]
    cmp edx,0
    jne .pregatire
    
    ;daca e par si  afisam normal
    
    mov eax,[ebp+8]
    pushad
    push eax
    push format
    call _printf
    add esp,4*2
    popad
    
    jmp .finish
        
     .pregatire:
        pop esi ;la finalul sirului + 1
        sub esi,2 ; ultima litera
     
        std
     .e_impar:
        lodsb
        movzx eax,al
        pushad
        push eax
        push format2
        call _printf
        add esp,4*2
        popad
     loop .e_impar
        
        
        
    .finish:
    cld
    mov esp,ebp
    pop ebp
    ret
    


