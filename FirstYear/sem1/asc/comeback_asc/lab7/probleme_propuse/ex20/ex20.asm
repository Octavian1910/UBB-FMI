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
    ; ;Sa se citeasca de la tastatura in baza 16 doua numere a si b de tip dword si sa se afiseze suma partilor low si diferenta partilor high. Exemplu:
    ; a = 00101A35h, b = 00023219h
    ; suma = 4C4Eh
    ; diferenta = Eh
    a dd 0
    b dd 0
    format db "%x %x" , 0
    mesaj1 db "Suma = %x " , 0
    mesaj2 db "Diferenta = %x " , 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        ;scanf(format , a , b)
        push b
        push a
        push format
        call [scanf]
        add esp,4*3
        
        mov eax,[a]
        mov ebx,[b]

        
        add ax,bx
        cwde 
        ;printf(suma , al )
        push eax
        push mesaj1
        call [printf]
        add esp,4*2
        
        
        mov eax,[a]
        mov ebx,[b]
        
        push eax 
        pop ax
        pop dx
        push ebx 
        pop bx
        pop cx
        
        
        sub dx,cx
        movsx edx,dx
        
        ;printf(diferenta , bl )
        push edx
        push mesaj2
        call [printf]
        add esp,4*2
      
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
