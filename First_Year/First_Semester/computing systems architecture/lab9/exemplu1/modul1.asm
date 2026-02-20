bits 32

extern _citireSirC
extern _str3

extern _printf

global _asmConcat


segment data public data use32
    lenRez dd 0
    adresaSirRezultat dd 0
    adresaSirParam dd 0
    adresaSirCitit dd 0
    mesaj db "Sirul 2 citit din modul asm",0
    
    
segment code public code use32

_asmConcat:
    push ebp
    mov ebp,esp
    
    ;alocam 12 bytes pe stiva pt cele 11 caractere
    sub esp,4*3
    
    mov eax,[ebp+8] ;sir1
    mov [adresaSirParam],eax
    
    mov eax,[ebp+12] ;unde scriem rezultatul
    mov [adresaSirRezultat],eax
    
    ;practic am alocat 12 octeti din care doar 11 o sa fie folositi
    mov [adresaSirCitit],ebp
    sub dword [adresaSirCitit],4*3
    
    ;afisam mesaj pt citire
    push dword mesaj
    call _printf
    add esp,4*1
    
    ;citim
    push dword [adresaSirCitit]
    call _citireSirC
    add esp,4*1
    
    ;concatenam
    ;sir1 la rezultat
    cld
    mov edi,[adresaSirRezultat]
    mov esi,[adresaSirParam]
    mov ecx,10
    rep movsb
    
    ;concatenam
    ;sir de la tastatura la rezultat
    add dword [lenRez], 10
    mov edi,[adresaSirRezultat]
    mov esi,[adresaSirCitit]
    mov ecx,10
    rep movsb
    
    ;concatenam
    ;sir definit global la rezultat
    add dword [lenRez],10
    mov edi,[adresaSirRezultat]
    mov esi,[adresaSirCitit]
    mov ecx,10
    rep movsb
    add dword [lenRez], 10
    
    mov eax,[lenRez]
    mov esp,ebp
    pop ebp
    ret
    
    
    
    
    
  