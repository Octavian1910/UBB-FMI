bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,printf,scanf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import printf msvcrt.dll
import scanf msvcrt.dll
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
; Se da un numar natural a (a: dword, definit in segmentul de date). Sa se citeasca un numar natural b si sa se calculeze: a + a/b. Sa se afiseze rezultatul operatiei. Valorile vor fi afisate in format decimal (baza 10) cu semn.
    
    a dd 25
    b dw 0
    mesaj1 db "A = ",0
    mesaj2 db "B = ",0
    mesaj3 db "%d",0
    format db "%d",0
    
    
    rezultat dd 0

; our code starts here
segment code use32 class=code
    start:
        ; ...
        

        
        ;printf
        push dword mesaj2
        call [printf]
        add esp,4*1
        
        ;scanf
        push dword b
        push dword format
        call [scanf]
        add esp,4*2
        
        
        
        ;a/b
        ;pune a in dx : ax
        push word [a+2]
        push word [a]
        pop ax
        pop dx
        idiv word [b] ; ax = dx:ax / b dx = dx:ax % b
    
        movsx eax,ax
        add eax,[a] ;eax = a + a/b
        mov [rezultat] , eax
        
        ;printf
        push dword [rezultat]
        push mesaj3
        call [printf]
        add esp,4*2
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
