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

    a db 10
    b dw 10
    c dw 10
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;Byte - 8
        ;Word - 16
        ;DWord - 32
        ;QWord - 64
        
        ;Pentru add
        add eax,ebx
        add eax,[c]
        add [c],eax
        add eax , 10
        add DWord [c],10
        
        ;Pentru sub
        sub eax,ebx
        sub eax,[a]
        sub [a],eax
        sub eax,10
        sub Dword [b],10
        
        ;Pentru mul
        mul bl ; ax = al * bl
        mul bx ; dx:ax = ax * bx
        mul ebx ; edx : eax = eax * ebx ; eax
        
        mul byte [a]
        mul word [b]
        
        ; Div
        div bl ; al = ax / bl  ah = ax % bl
        div bx ; ax = dx:ax / bx  dx = dx:ax % bx
        div ebx ; eax = edx : eax / ebx ; edx = edx : eax %ebx
        
        div byte [a] ; al = ax / a  ; ah = ax % a
        div word [b] ; ax = dx:ax / b ;dx = dx:ax % b 
        div dword [c] ; eax = edx:eax / c ; edx = edx : eax % c
        
        
        ;inc 
        inc ax
        inc byte [a]
        
        ;dec 
        dec ax
        dec byte[a]
        
        ;neg 
        neg ax  ; ax = 0 - ax
        neg byte [a] ; a = 0 - a
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
