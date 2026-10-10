bits 32 ; assembling for the 32 bits architecture

; Se dau cuvintele A si B. Se cere cuvantul C format astfel:
;- bitii 0-2 ai lui C coincid cu bitii 10-12 ai lui B
;- bitii 3-6 ai lui C au valoarea 1
;- bitii 7-10 ai lui C coincid cu bitii 1-4 ai lui A
;- bitii 11-12 ai valoarea 0
;- bitii 13-15 ai lui C concid cu inversul bitilor 9-11 ai lui B

; Vom obtine cuvantul C prin operatii succesive de "izolare". Numim operatia
; de izolare a bitilor 10-12 ai lui B, pastrarea intacta a valorii acestor
; biti, si initializarea cu 0 a celorlalti biti. Operatiunea de izolare se
; realizeaza cu ajutorul operatorului and intre cuvantul B si masca
; 0001110000000000. Odata bitii izolati, printr-o operatie de rotire se
; deplaseaza grupul de biti doriti in pozitia dorita. Cuvantul final se
; obtine prin aplicarea operatorului or intre rezultatele intermediare
; obtinute in urma izolarii si rotirii.
; Observatie: rangul bitilor se numara de la dreapta la stanga

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
     a dw 0111011101010111b
     b dw 1001101110111110b
     c dw 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        bx = 0 ; in bx calculam rezultatul
                   
        mov ax,0001110000000000b
        and ax,[b]
        mov cl,10
        rhl ax,cl
        
        or bx,ax
        or bx,0000000001111000b
        
        mov ax,[a]
        and ax,0000000000011110b
        mov cl,6
        rhl ax,cl
        or bx,ax
        
        and bx,1110011111111111b
        
        
        mov ax,[b]
        not ax
        and ax,0000111000000000b
        mov cl,4
        ror ax,cl
        or bx,ax
        
        mov [c],bx
        
        
        
        
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
