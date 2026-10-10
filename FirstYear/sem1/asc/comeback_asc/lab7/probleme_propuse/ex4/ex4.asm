bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit ,scanf,printf             ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
 import scanf msvcrt.dll
 import printf msvcrt.dll
                          
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
        ; Se dau doua numere naturale a si b (a, b: word, definite in segmentul de date). Sa se calculeze produsul lor  si sa se afiseze in urmatorul format: "<a> * <b> = <result>"
        ; Exemplu: "2 * 4 = 8"
        ;Valorile vor fi afisate in format decimal (baza 10) cu semn.
        
        a dw 0
        b dw 0
        
        temp_a dd 0
        temp_b dd 0
        
        mesaj1 db "A = ",0
        mesaj2 db "B = ",0
        mesaj3 db "%d * %d = %d",0
        result dd 0
        format db "%d",0
        rezultat dq 0
        
        
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;printf(a=)
        push dword mesaj1
        call [printf]
        add esp,4*1
        
        ;scandf(format , a)
        push dword temp_a
        push dword format
        call [scanf]
        add esp,4*2
        
        mov eax,[temp_a]
        mov [a],ax
        
        ;printf(b=)
        push dword mesaj2
        call [printf]
        add esp,4*1
        
        ;scandf(format , b)bits 32 ; assembling for the 32 bits architecture

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

        push dword temp_b
        push dword format
        call [scanf]
        add esp,4*2
       
        
        mov eax,[temp_b]
        mov [b],ax
       
        mov ax,[a]
        imul word [b] ; dx:ax = ax * b
        push dx
        push ax
        pop dword [result]
        
        ;scanf
        push dword [result]
        push dword [temp_b]
        push dword [temp_a]
        push dword mesaj3
        call [printf]
        add esp,4*4
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
