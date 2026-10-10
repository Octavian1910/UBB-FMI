bits 32 ; assembling for the 32 bits architecture

;Se dau 2 siruri de octeti A si B. Sa se construiasca sirul R care sa contina elementele lui B in ordine inversa urmate de elementele in ordine inversa ale lui A.

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    a db 2,1,-3,0
    la equ $-a
    b db 4, 5, 7, 6, 2, 1
    lb equ $-b
    d times la+lb db 0
    
     
    ;R: 1, 2, 6, 7, 5, 4, 0, -3, 1, 2

; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov ecx,lb ;cate elemente are de parcurs
        mov edi,0 ;indicele cu care parcurgem d
        mov esi,b+lb-1 ; incepem de la finalul sirului b
        jecxz urm_pas
        mutaB:
            mov al,[esi]    ;mutam in al valoarea din sirul b
            mov [d+edi],al  ;mutam in d valoarea din sirul b
            dec esi         ;mergem cu indexul la elementul din stanga in b
            inc edi         ;crestem indexul unde vom adauga urm valoare in d
            loop mutaB      ;scadem ecx
        
        urm_pas:
        mov ecx,la ;cate elemente are de parcurs
        mov esi,a+la-1 ; incepem de la finalul sirului a
        jecxz finish
        mutaA:
            mov al,[esi]    ;mutam in al valoarea din sirul a
            mov [d+edi],al  ;mutam in d valoarea din sirul a
            dec esi         ;mergem cu indexul la elementul din stanga in a
            inc edi         ;crestem indexul unde vom adauga urm valoare in d
            loop mutaA      ;scadem ecx
        
        finish:
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
