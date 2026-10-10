bits 32

global _parsare

segment data public data use32
zece dd 10


segment code public code use32


_parsare:

    push ebp
    mov ebp,esp
    
    mov esi,[ebp + 8]
    mov edi,[ebp + 12]
    xor edx,edx
    xor ecx,ecx
    
    .parcurge:
        lodsb
        cmp al,0
        je .finish
        cmp al,10
        je .finish
        cmp al,'b'
        je .salvare
        cmp al,','
        je .parcurge
        cmp al,39
        je .parcurge
        
        cmp al,'0'
        je .pune_zero
        
        ;pune unu altfel
        shl edx,1
        add edx,1
        jmp .parcurge
        
        .pune_zero:
         shl edx,1
         add edx,0
       
        
        jmp .parcurge
        
      .salvare:
        mov eax,edx
        stosd
        xor edx,edx
        inc ecx ;ct de numere
      jmp .parcurge
      
    .finish:
     
    mov eax,ecx ;salvam ct de numere
    mov esp,ebp
    pop ebp
    ret

        
        
    