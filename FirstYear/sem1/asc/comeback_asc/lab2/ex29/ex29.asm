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
    ;[b*c-(e+f)]/(a+d)
    a db 120
    b db 124
    c db 15
    d db 12
    
    e dw 12
    f dw 487

; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;b*c
        mov al,[b]
        mul byte [c] ; ax = al * c = b * c
        
        mov bx,[e]
        add bx,[f] ; bx = e + f
        
        sub ax,bx ; ax = ax - bx = b*c - (e + f)
        
        mov bl , [a]
        add bl , [d] ; bl = a + d
       
        div bl ; al = ax / bl  ; ah = ax % b
               ; al = (b*c - (e + f) ) /  (a+d)
        
        
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
