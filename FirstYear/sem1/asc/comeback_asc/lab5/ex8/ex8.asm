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
; Se da un sir de caractere S. Sa se construiasca sirul D care sa contina toate literele mari din sirul S.
; Exemplu:
 s db  'a', 'A', 'b', 'B', '2', '%', 'x', 'M'
 lens equ $-s
 d times lens db 0
 A equ 'A' 
 Z equ 'Z' 



; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov esi,0
        mov edi,0
        mov ecx,lens
        start_loop :
            mov al,[s+esi]
            cmp al,A
            jb final_loop ;sare la final daca <A
            
            cmp al,Z
            ja final_loop ;sare ;a final daca >Z
            
            ;daca e ok
            mov [d+edi],al
            inc edi
            
            final_loop :
                inc esi
         
         loop start_loop
            
         
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
