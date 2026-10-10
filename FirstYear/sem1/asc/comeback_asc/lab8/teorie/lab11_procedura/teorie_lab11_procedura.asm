; programul calculeaza factorialul unui numar si afiseaza in consola rezultatul
; procedura factorial este definita in segmentul de cod si primeste pe stiva ca  si parametru un numar
bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,printf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll   
import printf msvcrt.dll   

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    format db "factorial = %d" , 10 , 13 , 0

; our code starts here
segment code use32 class=code
    ;definim procedura factorial
    factorial:
        mov eax,1
        mov ecx,[esp + 4]
        
        .repetabits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...

; our code starts here
segment code use32 class=code
    start:
        ; ...
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack

            mul ecx ; edx:eax = eax*ecx
        loop .repeta
    ret
            

    start:
        push dword 7 ; facem 7!
        call factorial ; rezultatul vine in eax
        
        ;afisam printf(format,nr)
        push eax
        push dword format
        call [printf]
        add esp,4*2
        
        push 0
        call [exit]
        
        

