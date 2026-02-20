bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,fopen ,printf ,fclose  ,fread         ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import fopen msvcrt.dll
import printf msvcrt.dll
import fclose msvcrt.dll
import fread msvcrt.dll
                          
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    ; Se da un fisier text. Sa se citeasca continutul fisierului, sa se determine litera mica (lowercase) cu cea mai mare frecventa si sa se afiseze acea litera, impreuna cu frecventa acesteia. Numele fisierului text este definit in segmentul de date.
    
    vector times 26 db 0 
    a equ 'a'
    z equ 'z'
    nume_fisier db "input.txt",0
    mod_acces db "r",0
    descriptor dd -1
    
    len equ 100
    len_sir dd 0
    
    text times (len + 1) db 0 
    
    nr_maxim dd 0
    frecv_maxima db 0
    
    format db "Litera este %c aparand de %d ori", 0
    
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;fopen(nume_fisier,mod_acces)
        push mod_acces
        push nume_fisier
        call [fopen]
        add esp,4*2
        
        mov [descriptor],eax
        
        cmp eax,0
        je finish
        
        ;fread(text,1,len,descriptor)
        push dword [descriptor]
        push dword len
        push 1
        push text
        call [fread]
        add esp,4*4
        
        
        
        
        cmp eax,0
        je finish
        mov [len_sir],eax
        
        mov esi,0
        mov ecx,dword [len_sir]
        loop_text:
            mov al,[text + esi] ; al = caracter curent
            
            cmp al,'a'
            jb nu_e_bun   ; < a
            
            cmp al,'z'
            ja nu_e_bun ; >z
            
            sub al,'a' ;
            
            movzx edi,al
            
            inc byte [vector + edi] ;contorizare
            
            ;verificare maxim
            mov al,[vector+edi]
            cmp al,[frecv_maxima]
            jbe nu_e_bun  
            
            ;daca trb schimbat 
             mov [frecv_maxima],al
             mov [nr_maxim], edi
            
            nu_e_bun :
                inc esi 
        loop loop_text  
        
        mov eax,'a'
        add [nr_maxim],eax ;convertim la litera
        
        movzx eax,byte[frecv_maxima]
        
        ;printf(format,val1,val2)
        push eax
        push dword [nr_maxim]
        push format
        call [printf]
        add  esp ,4*3
        ;fclose(descriptor)
        
        push dword [descriptor]
        call [fclose]
        add esp,4*1
        
        
        
        
        
              
            
            
            
            
            
            
            
            
        
        
        finish:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
