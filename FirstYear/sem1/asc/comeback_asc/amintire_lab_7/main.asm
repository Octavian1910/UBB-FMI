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

; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;fopen(nume_fisier,mod_acces)
        Moduri acces:
        -r ;read deschide un fiser care ERXISTA
        -w ;write scrie in fiser chiar daca exista sau nu , il creeaza
        -a ;append  la fel ca write dar daca exista scrie in continuare
        -r+ citire si scriere in fisier EXISTENT
        -w+ citire si scriere iar daca nu exista creeaz unul nou
        -a+ citire si adaugare
        
        -fopen(nume_fisier,mod_acces) => descriptor in eax pe care il folosim pt scriere / citire altfel 0
        -printf(descriptor)
        -freadf(text,1,len,descriptor) in eax => nr cuvinte
        -fclose(descriptor)
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
