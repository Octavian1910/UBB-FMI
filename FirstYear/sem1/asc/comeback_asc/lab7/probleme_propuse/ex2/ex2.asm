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
    ;Sa se citeasca de la tastatura doua numere a si b (in baza 10) si sa se calculeze a/b. Catul impartirii se ;va salva in memorie in variabila "rezultat" (definita in segmentul de date). Valorile se considera cu semn.
; our code starts here
    a dd 0
    b dd 0
    mesaj1 db "Primul numar este egal cu ",0
    mesaj2 db "Al doilea numar este egal cu ",0
    mesaj3 db "Rezultatul impartirii a/b este %d ",0
    format db "%d",0
    rezultat dd 0
    


segment code use32 class=code
    start:
        ; ...
        ;printf ("Primul nr este " )
        
        push dword mesaj1
        call [printf]
        add esp,4*1
        
        ;scandf (%d,a)
        push dword a
        push format
        call [scanf]
        add esp,4*2
        
        ;printf ("Al doilea  nr este " )
        
        push dword mesaj2
        call [printf]
        add esp,4*1
        
        ;scandf (%d,b)
        push dword b
        push dword format
        call [scanf]
        add esp,4*2
        
        ;daca b e 0 atunci trecem la finish
        cmp  dword [b],0
        je finish
        
        mov eax,[a]
        cdq ; edx:eax = a cu semn
        
        idiv dword [b] ; eax = edx:eax / b
        
        mov [rezultat],eax ;mutam in rezultat = a/b
        
        ;printf(Rez este %d , rezultat)
        push dword [rezultat]
        push dword mesaj3
        call [printf]
        add esp,4*2
        
        
        
        
        
        
        
        
        
        finish :
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
