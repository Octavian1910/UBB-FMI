bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
  ; Se da un sir de caractere S. Sa se construiasca sirul D care sa contina toate caracterele speciale (!@#$%^&*) din sirul S.
; Exemplu:

    s db '+', '4', '2', 'a', '@', '3', '$', '*'
    lens equ $ - s
    d db '@','$','*'
    lend equ $ - d
    rezultat times lens db 0 
    

; our code starts here
segment code use32 class=code
    start:
        ; ...
          mov ecx,lens
          mov edi,0
          mov esi,0
          loops :
            mov al,[s+esi]
            push ecx  ;o sa se strice ecx in urm loop
            push esi
            mov esi,0
            mov ecx,lend
            loopd :
                mov bl,[d+esi]
                cmp al,bl
                je scrie_in_rezultat
                
                jmp sub_scrie_in_rezultat
                
                scrie_in_rezultat :
                    mov [rezultat+edi],bl
                    inc edi
                sub_scrie_in_rezultat :
                   inc esi
             loop loopd
             
             pop esi
             pop ecx
             inc esi
             loop loops
                
            
          
        finish:
        
            
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
