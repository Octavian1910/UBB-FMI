bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fopen   , fclose ,fprintf            ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll

 ; Se da numele unui fisier si un numar pe cuvant scris in memorie. Se considera numarul in reprezentarea fara semn. Sa se scrie cifrele zecimale ale acestui numar ca text in fisier, fiecare cifra pe o linie separata.                         
                   

 
                   
                          
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
        
    nume_fisier db "ana.txt",0
     numar dw 7584
     mod_acces db "a",0
     
     descriptor dd -1
    
    format db '%c' , 10 , 0
    
      
; our code starts here
segment code use32 class=code
    start:
        ; ...
         ;fopen(nume,mod)
        push mod_acces
        push nume_fisier
        call [fopen]
        add esp,4*2
        
        mov [descriptor] , eax
        cmp eax,0
        je finish
        
        movzx eax,word [numar]
        loop_numar : ;luam cifra cu cifra
        
            cmp word [numar],0
            je sub_loop
        
        ;deimpartit
            mov eax,0 ;curatam eax
            mov edx,0 ; partea high
            mov ax,[numar] ;punem numar
            
            ;impartitor
            mov ecx,10 
            
            div ecx; eax = edx:eax / ecx edx = edx:eax % 10
            add edx,'0' ;transformam in caracter 
            
            
            
            push eax
            
            ;fprintf(descriptor,format,numar)
            push edx
            push format
            push dword [descriptor]
            call [fprintf]
            add esp,4*3
            
            pop eax
            mov [numar],ax ; actualizam numarul la catul nou
            
        jmp loop_numar
        
        
        
        
        
        sub_loop:
        ;fclose(descriptor)
        push dword [descriptor]
        call [fclose]
        add esp, 4*1
        
        finish:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
