bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        


; declare external functions needed by our program
extern exit,fopen,fclose,fread,printf      
import exit msvcrt.dll    
import fopen msvcrt.dll    
import fclose msvcrt.dll    
import fread msvcrt.dll    
import printf msvcrt.dll    

                          
 ; Se dă un fișier text input.txt, care conține un șir de caractere. Să se determine și să se afișeze pe ecran numărul de apariții al fiecărei litere din fișier. Literele mari și mici se vor considera la fel (nu se face diferență între majuscule și minuscule). Se vor afișa doar literele care apar în text, împreună cu numărul lor de apariții.                         
                          
                          
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    
    nume_fisier db "input.txt",0
    mod_acces db "r" , 0
    litere times 26 db 0  ;vector de frecventa pt litere
    
    descriptor dd -1
    len equ 100
    text times (len+1) db 0
    
    format db "%c: %d%",10,0
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        
        ;fopen(nume_fisier,mod_acces)
        
        push mod_acces
        push  nume_fisier
        call [fopen]
        add esp , 4*2
        
        mov [descriptor] , eax
        cmp eax,0
        je finish
        
        ;fread(text,1,len,descriptor)
        push dword [descriptor]
        push len
        push 1
        push text
        call [fread]
        add esp,4*4
        
        cmp eax,0  ;verificam daca s au citit elemente
        je finish 
    
        ;parcurgem textul si contorizam doar literele
        mov esi,0
    
        parcurgere_text :
            mov al,[text + esi]  ;elementul de pe poz i din sir
            
            cmp al,0            ;am ajuns la caracterul null deci se termina
            je sub_parcurgere_text
            
            cmp al,'a'
            jb e_litera_mare_mare   ;daca e mai mic decat a => litere mari
            
            cmp al,'z'
            ja urm_elem ; daca e peste z nu e ok
            
            mov bl,'a'-'A'
            sub al,bl    ;convertim la litera mare
            
            jmp sub_e_litera_mare_mare
            e_litera_mare_mare :
               cmp al,'A'
               jb urm_elem  ; nu e intre A si Z
               
               cmp al,'Z'
               ja urm_elem ;nu e intre A si Z
               
            
            sub_e_litera_mare_mare:
            
            mov bl,'A'
            sub al,bl ; a cata litera este 
            ; acum trb sa contorizam
            mov ebx,0
            mov bl,al
            mov edi,ebx
            inc byte [litere + edi] ; contorizam litera
            
            urm_elem :
                inc esi 
         jmp parcurgere_text
         
         
         sub_parcurgere_text :
         
         
         ;afisam vectorul
         mov esi,0
         mov ecx,26
         parcurgere_vector:
            mov eax,0
            mov al,[litere + esi]      

            cmp al,0        ;afisam doar caracterele care apar
            je nu_trb_afisat
            
            mov ebx,esi
            add bl,'A'
            
            pushad              
            ;printf(format,%c,%d)
            push eax
            push ebx
            push format
            call [printf]
            add esp , 4*3
            
            popad 
     
            
            nu_trb_afisat :
                inc esi
          loop parcurgere_vector
 
            
      
        
        ;fclose(descriptor)
        push dword [descriptor]
        call [fclose]
        add esp,4*1
        
        
        
        finish:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
