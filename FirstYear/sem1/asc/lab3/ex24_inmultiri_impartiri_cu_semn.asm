bits 32 ; assembling for the 32 bits architecture
; declare the EntryPoint (a label defining the very first instruction of the program)
global start        
;a-(7+x)/(b*b-c/d+2); a-doubleword; b,c,d-byte; x-qword cu semn
; declare external functions needed by our program
extern exit            ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                       ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a dd 1000          ; a = 1000 (doubleword)
    b db 5             ; b = 5 (byte)
    c db 20            ; c = 20 (byte)
    d db 4             ; d = 4 (byte)
    x dq 100           ; x = 100 (qword)
    rezultat resd 1    ; variabilă pentru rezultat
    
; our code starts here
segment code use32 class=code
    start:
        mov al, [b]     ; AL = b = 5
        imul byte [b]    ; AX = b*b = 25
        
        movsx ebx, ax   ; EBX = b*b = 25
        
        mov ax, 0      
        mov al, [c]     ; AL = c = 20
        idiv byte [d]    ; AL = c/d = 5
        
        movsx ecx, al   ; ECX = c/d = 5
        
        sub ebx, ecx    ; EBX = b*b - c/d = 20
        add ebx, 2      ; EBX = b*b - c/d + 2 = 22
 
        mov eax, [x]    ; EAX partea low a lui x = 100
        mov edx, [x+4]  ; EDX partea high a lui x = 0
        
        add eax, 7      ; eax = a + 7 = 107
        adc edx, 0      ; edx = edx + CF
       
        div ebx         ; eax = 4 
        
        mov ecx, [a]    ; ECX = a = 1000
        sub ecx, eax    ; ECX = 1000 - 4 = 996

        mov [rezultat], ecx ; ecx = 996 = 000003E4h
        
        ; exit(0)
        push dword 0
        call [exit]