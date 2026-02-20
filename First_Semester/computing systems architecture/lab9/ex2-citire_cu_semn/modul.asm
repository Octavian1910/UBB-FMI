bits 32
global _conversie


segment data public data use32
    semn    dd 1
    lungime dd 0
    format db "%d",0

segment code public code use32
_conversie:
    push ebp
    mov  ebp, esp
    cld
    
    
    mov  esi, [ebp+8]       ; char* sir
    mov  edi, [ebp+12]      ; int* v

 
    mov  dword [semn], 1
   
    xor  edx, edx
    xor  ecx, ecx
    

citeste:
    
    lodsb
    cmp  al, 0
    je   final_sir

    cmp  al, 10             ; '\n' = sfârșit linie
    je   delim

    cmp  al, '-'
    je   minus

    cmp  al, '0'
    jb   delim
    cmp  al, '9'
    ja   delim

    movzx ebx, al
    sub  ebx, '0'
    imul edx, edx, 10
    add  edx, ebx
    mov  ecx, 1
    jmp  citeste

minus:
    mov  dword [semn], -1
    jmp  citeste

delim:
    cmp  ecx, 0
    je   citeste

    
    mov  eax, edx
    imul eax, dword [semn]
    mov  [edi], eax
    add  edi, 4
    inc  dword [lungime]
    xor  edx, edx
    xor  ecx, ecx
    mov  dword [semn], 1
    jmp  citeste

final_sir:
    cmp  ecx, 0
    je   finish

    mov  eax, edx
    imul eax, dword [semn]
    mov  [edi], eax
    inc  dword [lungime]

finish:
    mov  eax, [lungime]
    mov  esp, ebp
    pop  ebp
    ret
