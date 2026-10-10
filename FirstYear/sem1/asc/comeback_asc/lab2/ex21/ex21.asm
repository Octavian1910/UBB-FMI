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

;(f*g-a*b*e)/(h+c*d)
    a db 1
    b db 15
    c db 18
    d db 19
    
    e dw 215
    f dw 654
    g dw 142
    h dw 42
    
; our code starts here
segment code use32 class=code
    start:
        
    ;f*g
    
    mov ax , [f]
    mul word [g] ; dx:ax = ax * g
    
    push dx
    push ax
    ;stiva arata
    ; AX
    ; DX
    pop ecx  ; ecx = DX AX = f * g
    
    ;ax = f*g
    
    ;a*b*e  a , b byte
    mov al , [a]
    mul byte [b] ; ax = al * b = a * b
    mul word [e] ; dx : ax = ax * e = a * b * e
    push dx
    push ax
    pop ebx ; ebx = dx:ax = a*b*e
    
    ; fg - abe
    sub ecx , ebx ; ecx = fg - abe 
    
    
    ;(h+c*d)
    
    ;c*d
    mov al,[c]
    mul byte [d] ; ax = al * d  = c * d
    add ax , h ; ax = ax + h = h + c*d
    mov bx , ax ; bx = h+c*d facem asa ca sa putem face div
    ;ecx = fg - abe
    ;bx = h + c*d
    ; ecx/bx
    
    push ecx
    pop ax
    pop dx
    
    div bx ;  ax = dx:ax / bx ; dx = dx:ax % bx
    
    
