;	
;Se da un sir de caractere format din litere mici.
;Sa se transforme acest sir in sirul literelor mari corespunzator.

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
    segment data use32 class=data
	s db 'a', 'b', 'c', 'm','n' ; declararea sirului 
    
    l equ $ - s
    d times l db 0 ;aloca 5 elemente
    
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov ecx,l  ; lungimea in ecx ca sa parcurga l elemente
        
        mov esi , 0 ; sursa 0 
        jecxz Sfarsit ; daca lungimea lui ecx e 0
        
        Repeta:
        
            mov al,[s+esi]
            mov bl,'a'-'A'
            sub al,bl
            mov [d+esi], al
            inc esi
         loop Repeta
            
          Sfarsit:
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
