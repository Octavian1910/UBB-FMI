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
       
     ;TIPURI DE INSTRUCTIUNI PE SIRURI :
     
     
     -care folosesc un sir sursa si un sir destinatie
          DESTINATIE <- SURSA
      EX :
          MOVSB , MOVSW , MOVSD , CMPSB,CMPSW,CMPSD
      
      -care folosesc NUMAI UN SIR SURSA :
       EX:
        LODSB , LODSW,LODSD
        
       -care folosesc numai un sir destinatie
       
        STOSB,STOSW,STOSD,SCASB,SCASW,SCASD
        
        Move String = MOVS
        Compare String = CMPS
        Load String = LODS
        Store String = STOS
        Scan String = SCAS
        
        DS:ESI -pt sirul sursa
        ES:EDI - pt sirul destinatie
        
        Directia de parcurgere :
         CLD
         STD
         
         
         LODSB :
            AL = DS:ESI  
            ;DACA CLD : INC ESI 
            ;DACA STD : DEC ESI
            
         STOSB :
         ES:EDI = AL
         
         MOVSB :
         ES:EDI = DS:ESI
         
            
        ;suprascriere sir
        sir times 20 db 0
        mov al,0
        mov ecx,20
        rep stosb
        ; edi +1 
       
        
         
       
; our code starts here
segment code use32 class=code
    start:
        ; ...
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
