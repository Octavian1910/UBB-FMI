bits 32 

global _creeare_numar

segment data public data use32

numar dd 0

segment code public code use32
    
   
_creeare_numar:
    push ebp
    mov ebp,esp
    xor edx,edx
 
    mov esi,[ebp + 8] ;sir1
    mov edi,[numar]
    parcurge:
        lodsb
        cmp al,0
        je finish
        
        cmp al,'1'
        je pune_unu
        
        pune_zero:
            shl edx,1
            add edx,0
        jmp parcurge
        
        pune_unu:
            shl edx,1
            add edx,1
   jmp parcurge
        
    finish:
    mov eax,edx
    mov esp,ebp
    pop ebp
    ret
    
    
    
    
    
    
    