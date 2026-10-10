bits 32 ; assembling for the 32 bits architecture
; declare the EntryPoint (a label defining the very first instruction of the program)
global start        
;a - byte, b - word, c - double word, d - qword - Interpretare cu semn
;((a + a) + (b + b) + (c + c)) - d
; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db -10       
    b dw 25        
    c dd 100       
    d dq 50
    rezultat resq 1
    
; our code starts here
segment code use32 class=code
    start:
        mov al, [a]         ; al = -10
        cbw                 ; ax = -10
        add ax, ax          ; ax = 2*a = -20
        cwde                ; eax = -20
        
        movsx ebx, word [b] ; ebx = 25 
        add ebx, ebx        ; ebx = 2*b = 50
        
        add eax, ebx        ; eax = -20 + 50 = 30
        
        mov ebx, [c]        ; ebx = 100
        add ebx, ebx        ; ebx = 2*c = 200
        
        add eax, ebx        ; eax = 30 + 200 = 230
        
        cdq                 ;EDX:EAX    
        
        sub eax, [d]        ; eax = 230 - 50 = 180 (partea low)
        sbb edx, [d+4]      ; edx = 0 - 0 - carry (partea high)
        
        mov [rezultat], eax      ;  partea low
        mov [rezultat+4], edx    ;  partea high
        
        ; exit(0)
        push dword 0
        call [exit]