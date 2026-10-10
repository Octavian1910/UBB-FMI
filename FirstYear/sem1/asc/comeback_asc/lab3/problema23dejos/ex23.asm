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
    ;(a*b-2*c*d)/(c-e)+x/a; 
    ;a,b,c,d-byte; e-word; x-qword  CU SEMN
    a db 15
    b db 14
    c db 124
    d db 14
    
    e dw 245
    
    x dq 147
    
    
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
   
        ;x+a
        mov eax ,[x]
        mov edx , [x+4]
        movsx ebx , byte [a]
        idiv ebx ; eax = edx:eax / a
        push eax
        
        ; a * b
        mov al,[a]
        cbw ; ax = a
    
        movsx cx,byte [b]
        imul cx ; dx:ax = ax * b = a*b
        
        push dx
        push ax
        pop ebx ;ebx = dx : ax = a * b
        
        movsx ax , byte [d]
        
        movsx cx,byte [c]
        imul cx ; dx:ax = ax * c = d *c
        
        push dx
        push ax
        pop eax
        
        shl eax,1 ; eax = eax * 2
        
        sub ebx,eax ; ebx = a*b-2*c*d
        
        mov al,[c]
        cbw ; ax = c
        sub ax,[e]
        cwde ; eax = c-e
 
        mov ecx,eax ; ecz = c-e
        mov eax , ebx ; eax = a*b-2*c*d
        
        cdq ; edx:eax = a*b-2*c*d
        
        idiv ecx  ; eax = edx: eax / ecx = (a*b-2*c*d)/(c-e)
        
        pop edx ; edx = x/a
        add eax,edx
        
        
        
        
        
        
        
        
        
        
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
