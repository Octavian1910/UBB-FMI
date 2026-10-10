bits 32

extern printf
import printf msvcrt.dll


segment data use 32 class=data
rezultat1 times 100 db 0  ; cifre1+cifre2
rezultat2 times 100 db 0  ; cifre2+cifre1
format db "%s",13,10,0

segment code use32 public code
global concatenari

concatenari:
    mov ebx,[esp+8] ;sir2
    mov eax,[esp+4];sir1
    
    
    mov esi,eax
    mov edi,rezultat1
    cld  ;st la dr
    
    loop_sir_1:      ;sir1+sir2
        lodsb  ; al = esi
        cmp al,0
        je terminare_loop_sir_1
        cmp al,'0'
        jb loop_sir_1
        cmp al,'9'
        ja loop_sir_1
        
        stosb ;incarca in al ce e in edi
    jmp loop_sir_1
    
    terminare_loop_sir_1:
    mov esi,ebx
    loop_sir_2: 
        lodsb  ; al = esi
        cmp al,0
        je afisare
        cmp al,'0'
        jb loop_sir_2
        cmp al,'9'
        ja loop_sir_2
        stosb
    jmp loop_sir_2
    
   
    
    afisare:
    ;terminare sir concatenat
    mov al,0
    stosb
    
    ;printf(format,sir_concatenat)
    push rezultat1
    push format
    call [printf]
    add esp, 4*2
         
    ret 4*2