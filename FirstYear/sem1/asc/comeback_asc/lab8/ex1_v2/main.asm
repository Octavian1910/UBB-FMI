 ;Se da un numar a reprezentat pe 32 biti fara semn. Se cere sa se afiseze reprezentarea in baza 16 a lui a, precum si ;rezultatul permutarilor circulare ale cifrelor sale.

bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,printf,modul              ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import printf msvcrt.dll
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    a dd 0001_0010_0011_0100_0101_0110_0111_1000b
    format_b16 db "Nr in baza 16 x = %x " ,10,13,0
    

; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;printf(format, & nr)
        push dword [a]
        push dword format_b16
        call [printf]
        mov ebp,4*2
        
        ;mai trb sa facem permutarile
        ;permutari(numar)
        push dword [a]
        call modul ; trb sa curatam stiva daca e cazul
        
        
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
