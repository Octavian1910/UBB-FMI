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
            d dw 200
            e dq 80

; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        ; mov al,[b]
        ; cbw ; ax = b cu semn
        ; cwd ; dx : ax = b cu semn
        
        ; idiv word [c] ; ax = dx:ax / c = b / c
            
        ; mov bx,ax  ; mutam rezultatul in bx

        mov ax,2
        imul word [d] ; ax = al * d = 2*d
                       ; dx : ax
        ; sub bx,ax ; bx = b/c - 2*d
        ; mov ax , bx
        ; cwde ; eax = b/c - 2*d
        
        ; mov ebx,[a]
        
        ; add ebx,eax ; ebx = a + b/c - 2*d
        ; mov eax , ebx 
        
        ; cdq ; edx:eax = a + b/c - 2*d
        
        ; sub eax,dword [e]
        ; sbb edx,dword [e+4]
            
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
