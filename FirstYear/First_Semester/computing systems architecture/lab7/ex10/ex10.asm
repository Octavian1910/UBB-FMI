bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit  , fprintf ,scanf ,gets  ,fopen,fclose            ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll
import fprintf msvcrt.dll
import scanf msvcrt.dll
import gets msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
; Sa se citeasca de la tastatura un nume de fisier si un text. Sa se creeze un fisier cu numele dat in directorul curent si sa se scrie textul in acel fisier. Observatii: Numele de fisier este de maxim 30 de caractere. Textul este de maxim 120 de caractere.
    

format1 db "%s",0
format2 db "%s",0


mod_acces db "w",0
descriptor dd -1

nume times 30 db 0    
text times 120 db 0    



; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        ;scanf(format ,nume n)
        push nume 
        push format1
        call [scanf]
        add esp,4*2
        
        ;gets(text)
        push text 
        call [gets]
        add esp,4*1
        
        ;fopen(nume_fisier,mod_acces)
        push mod_acces
        push nume
        call [fopen]
        add esp,4*2
        
        mov [descriptor] , eax
        cmp eax,0
        je finish
        
        ;fprintf(descriptor,text)
        push text
        push dword [descriptor]
        call [fprintf]
        add esp,4*2
        
        ;fclose
        push dword [descriptor]
        call [fclose]
        
        
        
        
        
        
        
        finish :
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
