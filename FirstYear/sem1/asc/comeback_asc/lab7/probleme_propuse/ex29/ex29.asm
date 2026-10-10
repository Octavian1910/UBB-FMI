bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit ,printf , scanf              ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import printf msvcrt.dll
import scanf msvcrt.dll

; Se citesc de la tastatura trei numere a, m si n (a: word, 0 <= m, n <= 15, m > n). Sa se izoleze bitii de la m-n ai lui a si sa se afiseze numarul intreg reprezentat de acesti bitii in baza 10.


; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    a dd 0
    m dd 0
    n dd 0
    temp dw 0
    format db "%d %d %d" ,0
    format2 db "%d",0
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        ;scanf(format , a ,m , n)
        push n
        push m
        push a
        push format
        call [scanf]
        add esp,4*4
        
        ;a = 00 00 h = 0000 0000 0000 0000
        
        mov ecx,[m]
        sub ecx,[n]
        add ecx,1
        
        punem_mn_de_1 :  ; punem m-n+1 de 1
            shl word [temp] , 1
            or word [temp],1
             
             
            
         
        
        loop punem_mn_de_1
        
        ;mutam la pozitiile corespunzatoare
        mov cl,[n]
        shl word [temp],cl
        
        mov eax,[temp]
        
        and  [a],eax
        
        ;afisare print(format,nr)
        push dword [a]
        push format2
        call [printf]
            
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
