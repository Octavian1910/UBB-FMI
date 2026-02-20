bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

extern exit, fprintf, fopen, fclose
import exit msvcrt.dll
import fprintf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
; Se dau un nume de fisier si un text (definite in segmentul de date). Textul contine litere mici, litere mari, cifre si caractere speciale. Sa se inlocuiasca toate caracterele speciale din textul dat cu caracterul 'X'. Sa se creeze un fisier cu numele dat si sa se scrie textul obtinut in fisier.
    
    nume_fisier db "input.txt",0
    text db "Ana are 12 x mere ! x si 12 pere!",0
    lens equ $-text
    mod_acces db "w",0
    caractere db "!@#$%^&*()"
    descriptor dd -1
    
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;fopen(nume,mod)
        push mod_acces
        push nume_fisier
        call [fopen]
        add esp,4*2
        
        mov [descriptor],eax
        cmp eax,0
        je finish
        
        
        mov esi,0
        parcurgere :
            mov al , [text + esi]
            cmp al , 0
            je sub_parcurgere
            mov edi,0
            verif_caracter_special :
                mov bl , [caractere + edi ]
                cmp bl,0
                je sub_verif_caracter_special
                cmp bl,al
                jne urm
                
                mov al,'x'
                mov [text + esi] , al
                
                urm : 
                inc edi
              jmp verif_caracter_special
              
              
              sub_verif_caracter_special:
              inc esi
              bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions


           jmp parcurgere
           
           sub_parcurgere:
           
           ;fprintf(descriptor,text)
           push  text
           push dword [descriptor]
           call [fprintf]
           add esp , 4*2
           
           ;fclose
           push dword [descriptor]
           call [fclose]
                
                
                
                
    
        finish:
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
