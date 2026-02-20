bits 32
;Se citeste de la tastatura un sir de mai multe numere in baza 2. Sa se afiseze aceste numere in baza 16.
global _baza2to16

extern _printf

segment data public data use32
format db "%x",0
lungime db 0

segment code public code use32

_baza2to16:
    push ebp
    mov ebp,esp
    mov esi,[ebp + 8]
    mov edi,[ebp + 12]
    xor eax,eax
    xor ecx,ecx ;contor
    xor ebx,ebx ;aici tinem rezultatul
    cld
    parcurge:

        lodsb
        cmp al,0
        je salvare
        
        cmp al,10
        je salvare
        
        cmp al,' '
        je salvare
        
        
        cmp al,'1'
        je pune_unu
      
        pune_zero:  ;altfel pune 0
        shl ebx,1
        add ebx,0
        inc byte [lungime]
        jmp parcurge
        
        
        pune_unu :
        shl ebx,1
        add ebx,1
        inc byte [lungime]
        jmp parcurge
        
        salvare:
            mov dl,al
            mov eax,ebx
            cmp byte [lungime],0
            je parcurge
            stosd
            xor ebx,ebx ;aici tinem rezultatul
            mov byte [lungime],0
            inc ecx
            cmp dl,0
            je terminare
            cmp dl,10
            je terminare
            
        jmp parcurge
        
    terminare:
    mov esp,ebp
    pop ebp
    mov eax,ecx
    ret     ;eax = in eax se afla numarul

    
    ;nasm modul.asm -fwin32 -o modul.obj
    ;cl main.c /link modul.obj