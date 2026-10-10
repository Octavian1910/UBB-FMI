;Se da dublucuvantul M. Sa se obtina dublucuvantul MNew astfel:
;bitii 0-3 a lui MNew sunt identici cu bitii 5-8 a lui M
;bitii 4-7 a lui MNew au valoarea 1
;bitii 27-31 a lui MNew au valoarea 0
;bitii 8-26 din MNew sunt identici cu bitii 8-26 a lui M.


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
      
    m dd 00011010001010110011110001001101b  
    mNew resd 1
       
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov ebx,0 ; in ebx tinem rezultatul deci il facem 0
        
        mov eax,[m]  ;folosim eax pentru a lucra cu a
        mov ecx,000000000000000000000000111100000b
        and eax,ecx ;izolam bitii de pe pozitiile 5-8
        mov cl,5 
        shr eax,cl ;mutam bitii sa fie pe pozitiile 0-3
        
        or ebx,eax ;mutam rezultatul in ebx
        
        or ebx,000000000000000000000000011110000b ;bitii 4-7 a lui MNew au valoarea 1
        
        and ebx,00000111111111111111111111111111b;bitii 27-31 a lui MNew au valoarea 0
        
        
        mov eax, [m]
        and eax, 00000111111111111111111100000000b ;bitii 8-26 din MNew sunt identici cu bitii 8-26 a lui M.
        or ebx, eax
        ; sau varianta grea
        ;mov eax,[m] ; mutam in eax m
        ;mov cl,8
        ;shr eax,cl
        ;shl eax,cl  ; stergem bitii 0-7
        ;mov cl,5
        ;shl eax,cl
        ;shr eax,cl ; stergem bitii 31-28
        ;or ebx,eax
        
        mov [mNew],ebx
        
        
        
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
