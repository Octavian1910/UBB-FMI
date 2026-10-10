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
    a dd 10111000011100000011100010000000b
    b dd 01000111000000111000001000000000b
; ;Se dau dublucuvintele A si B. Sa se formeze qwordul C in felul urmator:
; bitii 0-7 ai lui C sunt bitii 21-28 ai lui A
; bitii 8-15 ai lui C sunt bitii 23-30 ai lui B complementati
; bitii 16-21 ai lui C sunt 101010
; bitii 22-31 ai lui C au valoarea 0
; bitii 32-42 ai lui C sunt bitii 21-31 ai lui B
; bitii 43-55 ai lui C sunt bitii 1-13 ai lui A
; bitii 56-63 ai lui C sunt bitii 24-31 ai rezultatului A XOR 0ABh
    
; our code starts here

segment code use32 class=code
    start:
        ; ...
        mov edx,0 ;high
        mov ecx,0 ;low
        ;10987654321098765432109876543210
        ;00000000000000000000000000000000b
        ;00001111111100000000000000000000b
        
        ;bitii 0-7 ai lui C sunt bitii 21-28 ai lui A
        mov eax,[a]
               ;10987654321098765432109876543210
        and eax,00011111111000000000000000000000b
        mov cl,21
        shr eax,cl
        or ecx,eax
        
        ;bitii 8-15 ai lui C sunt bitii 23-30 ai lui B complementati
        mov eax,[b]
        not eax
               ;10987654321098765432109876543210
        and eax,01111111100000000000000000000000b
        mov cl,15
        shr eax,cl
        or ecx,eax

        ;bitii 16-21 ai lui C sunt 101010
              ;10987654321098765432109876543210
        or ecx,00000000001010100000000000000000b
        
        ;bitii 22-31 ai lui C au valoarea 0
              ;10987654321098765432109876543210
        and ecx,00000000001111111111111111111111b
    
    
        ;bitii 32-42 ai lui C sunt bitii 21-31 ai lui B
        
        mov eax,[b]
               ;10987654321098765432109876543210    
        and eax,11111111111000000000000000000000b
        mov cl , 21
        shr eax,cl
        
        or edx,eax
        
        ;bitii 43-55 ai lui C sunt bitii 1-13 ai lui A
        
        mov eax,[a]
               ;10987654321098765432109876543210
        and eax,00000000000000000011111111111110b
        mov cl,10
        shl eax,cl
        or edx,eax
        
        ;bitii 56-63 ai lui C sunt bitii 24-31 ai ;rezultatului A XOR 0ABh
        
        mov eax,[a]
        xor eax,0ABH
                ;10987654321098765432109876543210
        and eax ,11111111000000000000000000000000b
        or edx,eax 
        
        
      
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
