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
;Sa se citeasca de la tastatura doua numere a si b (in baza 10) si sa se calculeze: (a+b) / (a-b). Catul impartirii se va salva ;in memorie in variabila "rezultat" (definita in segmentul de date). Valorile se considera cu semn.
    
    a dd 0
    b dd 0
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
        push dword mesaj1
        call [printf]
        add esp,4*1
        
        ;scanf
        push dword a
        push dword format
        call [scanf]
        add esp,4*2
        
        
        ;printf
        push dword mesaj2
        call [printf]
        add esp,4*1
        
        ;scanf
        push dword b
        push dword format
        call [scanf]
        add esp,4*2
        
        
        
        ;a+b
        mov eax,[a]
        add eax,[b]  ; eax = a+b
        
        ;a-b
        mov ebx,[a]
        sub ebx,[b] ; ebx = a-b
    
        
        cdq ; edx:eax = a+b
        idiv ebx ; eax = edx:eax / ebx = (a+b) / (a-b)
        mov [rezultat],eax
        
        ;afisare 
        push dword [rezultat]
        push format
        call [printf]
        add esp , 4*2
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
