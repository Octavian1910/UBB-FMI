bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

;Adunări, scăderi
;a - byte, b - word, c - double word, d - qword - Interpretare fara semn
;24) ((a + b) + (a + c) + (b + c)) - d
; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    a db 18         
    b dw 15       
    c dd 50      
    d dq 87     
    rezultat dq 0
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov ebx,0
        mov eax,0
        mov al,[a] ;il punem pe a in ax
        mov bx,ax  ; bx = a
        
        add ax,[b] ; ax =  a+b  deci eax = a+b
                   ;eax=   a+b = 18 + 15 = 33
        
        add ebx,[c] ; ebx = a+c = 68
        
        mov ecx,0
        mov cx,[b]   ; in exc il punem pe b
        add ecx,[c] ; ecx = b+c = 65
        
        add eax, ebx ;eax = (a + b) + (a + c)
        add eax,ecx ; eax = (a + b) + (a + c) + (b + c) = 166 ;eax partea low
        
        mov ebx,0   ;ebx partea high , eax partea low
        
        mov ecx,[d]; ecx = 87 ;partea low
        mov edx,[d+4] ;partea high
        
        sub eax,ecx   ; eax = eax-ecx = 166-87 = 79 = 000000000000004Fh
        sbb ebx,edx   ; ebx = ebx-edx-1
        
        mov [rezultat], eax
        mov [rezultat+4], ebx
        
    
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
