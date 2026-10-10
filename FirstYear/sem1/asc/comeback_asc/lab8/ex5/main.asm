bits 32
global start

import printf msvcrt.dll
import exit msvcrt.dll
import scanf msvcrt.dll
extern printf, exit,scanf

extern operatie

segment data use32 class=data
    ; ...
    a dd 0
    b dd 0
    c dd 0
    cerinta db "a = ? b = ?  c = ?",10, 13, 0
    format db "%d %d %d",0
    rezultat db "a+b-c = %d",10, 13, 0

segment code use32 public code
start:
        ; ...
        ;afisam printf(format)
        push dword cerinta
        call [printf]
        add esp,4*1
        
        ;citim         scanf(format,a,b,c)
        push dword c
        push dword b
        push dword a
        push format
        call [scanf]
        add esp,4*4
        
        ;apelam operatia 
        push dword [c]
        push dword [b]
        push dword [a]
        call operatie ;ret 4*3
        
        ;afisare rezultat
        push eax
        push dword rezultat
        call [printf] 
        add esp,4*2
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call [exit]
