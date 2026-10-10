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
; Scrieți un program în limbaj de asamblare care să rezolve expresia aritmetică, considerând domeniile de definiție ale variabilelor
; a - doubleword; b, d - byte; c - word; e - qword
; a + b / c - d * 2 - e


    a dd 125
	b db 2
	c dw 15
	d db 200
	e dq 80

; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov al,[b]
        mov ah,0
        mov dx,0
        
        div word [c] ; ax =dx:ax  /c = b / call
        mov bx,ax ; mutam rezultatul in bx
        ;d*2
        mov al,2
        mul byte [d] ; ax = al / d
        
        sub bx,ax ; bx = b/c - d*2
        mov cx,0
        ;cx:bx = b/c-d*2
        
        mov ax,word [a]
        mov dx,word [a+2] ; dx:ax = a
        
        push dx
        push ax
        
        add ax,bx
        adc dx,cx ; dx:ax = a+ b/c + d*2
        
        push dx
        push ax
        pop eax ; eax = dx:ax
        
        mov edx,0
        sub eax , dword [e]
        sbb edx, dword [e+4]
        ; edx:eax = a + b/c - d*2 - e
        
        
        
        mov
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
