bits 32 ; assembling for the 32 bits architecture

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
           
        ;AND DACA AI 1 SI 1 => 1
        
        and eax , ebx
        and eax , [a]
        and [a] , eax
        and eax , 8
        and [a] , 8
        
        ;OR  DACA AI 0 SAU 1 => 1
        
        or eax,ebx
        or eax,[a]
        or [a],eax
        or eax,8
        or [a],8
        
        ;XOR DACA DOAR 1 DIN CEI 2 E ADEVARAT
        
        xor eax,ebx
        xor eax , [a]
        xor [a] , eax
        xor eax , 8
        xor [a] , 8
        
        xor eax , eax ; zerorizeaza continutul lui edx
        
        ;Test Face and fara sa puna
        
        test eax,ebx
        test eax,[a]
        test [a],eax
        test eax , 8
        test [a] , 8
        
        ;Not
        not eax
        not byte [a]
        
        ;shl ultimu bit se duce in CF
        shl eax,8
        shl byte [a],8
        shl eax,cl
        shl byte [a],8
        
        ;shr ultimu bit se duce in CF
        shr eax,8
        shr byte [a] , 8
        shr eax,cl
        shr byte [a], cl
        
        ;sal identic cu shl
        
        ;sar e shr dar pune in stanga bitul de semn
        
        ;rol 
        rol eax,8
        rol byte [a],10
        rol eax,cl
        rol byte [a],8
        
        
        
        
        
        
        
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
