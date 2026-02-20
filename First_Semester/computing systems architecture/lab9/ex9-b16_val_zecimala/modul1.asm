bits 32

global _parsare

extern _printf

segment data public data use32
saispe dd 16

segment code public code use32

_parsare:
    push ebp
    mov ebp,esp
    
    mov esi,[ebp+8] ;sir
    mov edi,[ebp+12] ;v
    xor edx,edx
    xor ecx,ecx
    
    parcurge:
        lodsb
        cmp al,0
        je salveaza
        cmp al,10
        je salveaza
        cmp al,' '
        je salveaza
        
        ;poate e cifra
        cmp al,'9'
        ja e_litera
        sub al,'0'  ;convertim la cifra
        jmp pune_la_nr  ;pune cifra la nr

        e_litera:
        sub al,'a' ;scadem 'a' => un nr  [0-5]
        add al,10 ; adunam 10 => un nr intre [10-15]
        
        pune_la_nr:
        mov bl,al
        movzx ebx,bl  ; convertim cifra la dword
        mov eax,edx
        mul dword [saispe]   ;eax = eax*16
        add eax,ebx   ; eax = eax * 16 + cifra
        mov edx,eax
        jmp parcurge
        
        salveaza:
            mov bl,al
            mov eax,edx
            stosd
            xor edx,edx
            inc ecx
            
            cmp bl,0
            je finish
            cmp bl,10
            je finish
            
        jmp parcurge
        
        
    jmp parcurge
    
    finish:
    
    mov edi,[ebp+16]
    mov [edi],ecx  ;punem lungimea sirului
    mov esp,ebp
    pop ebp
    ret   

