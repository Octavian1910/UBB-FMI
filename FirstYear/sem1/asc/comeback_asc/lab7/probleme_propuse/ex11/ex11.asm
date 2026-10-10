bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit  ,printf,scanf             ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import printf msvcrt.dll
import scanf msvcrt.dll
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
 ;Sa se citeasca de la tastatura un numar in baza 16 si sa se afiseze valoarea acelui numar in baza 10.
 ;Exemplu: Se citeste: 1D; se afiseaza: 29
; our code starts here

    mesaj1 db "Numarul este ",0
    mesaj2 db "Numarul in b10 este ",0
    numar dw 0
    format_baza16 db "%x",0
    format_baza10 db "%d",0
    
segment code use32 class=code
    start:
        ; ...
        ;printf
        push mesaj1
        call [printf]
        add esp,4*1
        
        ;scanf (%x ,&numar)
        push numar
        push format_baza16
        call [scanf]
        
        ;printf (%d, numar)
        push dword [numar]
        push format_baza10
        call [printf]
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
