bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit  ,printf,scanf             ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import printf msvcrt.dll
import scanf msvcrt.dll
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
; ;Sa se citeasca de la tastatura un octet si un cuvant. Sa se afiseze pe ecran daca bitii octetului citit se regasesc consecutiv printre bitii cuvantului. Exemplu:
; a = 10 = 0000 1010b
; b = 256 = 0000 0001 0000 0000b
; Pe ecran se va afisa NU.
; a = 0Ah = 0000 1010b
; b = 6151h = 0110 0001 0101 0001b
; Pe ecran se va afisa DA (bitii se regasesc pe pozitiile 5-12).


    a db 0 ;00
    b dw 0 ;00 00 b
    format db "%d %d",0
    mesaj_gasit db "Da",0
    mesaj_negasit db "Nu",0

; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;citim a si b
        push  b
        push  a
        push format
        call [scanf]
        add esp,4*3
        
        mov ecx,9 ;nr de biti
        movsx dx,byte [a]
        
        loop_b:
            mov ax,[b] ;ax = b
            and ax,dx ; and intre b si a
            cmp ax,dx ; daca ultimul octet a lui b sunt egali cu bitii lui a atunci scaderea lor = 0 
            je gasit  ; daca scaderea lor e 0 atunci sunt egali deci s a gasit
            shr word [b],1 ;acutalizam ultimul octet
            dec ecx
            cmp ecx,0
            je negasit ;daca s au efectuat 16 pasi adica cati biti are b s a terminat
            
            jmp loop_b
        
        gasit : 
            push mesaj_gasit
            call [printf]
            add esp,1*4
            jmp finish
            
        negasit : 
            push mesaj_negasit
            call [printf]
            add esp,1*4
        finish :
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
