
;Se cere se se citeasca numerele a, b si c ; sa se calculeze si sa se afiseze a+b-c.
bits 32 
global start        


extern exit,scanf,printf             
import exit msvcrt.dll  
import scanf msvcrt.dll  
import printf msvcrt.dll  
  
                          
extern calcul

segment data use32 class=data
    afisare db "a = b =  c  = ",0
    format db "%d %d %d",0
    rezultat db "a + b - c  = %d ",0
    a dd 12
    b dd 10
    c dd 2
    

segment code use32 class=code
    start:
        ;afisare mesaj 
        ;scanf(afisare)
        push afisare
        call [printf]
        add esp,4
        
        ;citim numerele
        ;scanf(format,&a,&b,&c)
        push dword c
        push dword b
        push dword a
        push format
        call [scanf]
        add esp,4*4
        
        ;le trimitem in functie
        ;calcu;(a,b,c)
        push dword [c]
        push dword [b]
        push dword [a]
        call calcul
        add esp,4*3
        
        ;afisam rezultatul
        ;printf(format,eax)
        push eax
        push rezultat
        call [printf]
        add esp,4*2
        
        push    dword 0     
        call    [exit]       
