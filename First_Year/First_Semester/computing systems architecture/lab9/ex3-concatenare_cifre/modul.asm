bits 32

global _concatenare
extern _printf
segment data public data use32

rezultat times 100 db 0
format db "%s",13,10,0

segment code public code use32


_concatenare:
    push ebp
    mov ebp,esp
    mov esi,[ebp + 8]
    mov edi,rezultat
    
    punere_nr_sir1:
        lodsb
        
        cmp al,0
        je finish1
        
        cmp al,'0'
        jb punere_nr_sir1
        
        cmp al,'9'
        ja punere_nr_sir1
        stosb
     jmp punere_nr_sir1
     
     finish1:
     mov esi,[ebp+12]
     
     punere_nr_sir2:
        lodsb
        
        cmp al,0
        je finish2
        
        cmp al,'0'
        jb punere_nr_sir2
        
        cmp al,'9'
        ja punere_nr_sir2
        stosb
     jmp punere_nr_sir2
     
     finish2:
     
     pushad
     push  dword rezultat
     push format
     call _printf
     add esp,4*2
     popad
     
     mov esp,ebp
     pop ebp
     ret
