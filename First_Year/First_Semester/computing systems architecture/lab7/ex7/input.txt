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
        
        eax = decriptor(pointer catre fisier ) = fopen(nume_fisier,mod_acces)
        
        mod_acces :
        r - read  opens a file which already exists
        w - write   creeaza un fisier daca nu exista 
        a - add  daca nu exista creeaza un fisier 
        r+ - read and write file must exist 
        w+ - read and write  creates a new one in need 
        a+ - read and add creates a new one in need 
    
        
        Scrierea intr un fisier 
        fprintf (descriptor,&text , 10 , a , etc)
        eax = -1 daca nu a functionat cred 
        eax >= 0 a mers
        eax < 0 nu a mers
        
        Citirea dintr un fisier 
        eax = nr_de_elem_citite = fread (sir_a,1,len,descriptor)
        
        Inchiderea unui fisier 
        fclose (decriptor)
        
    
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
