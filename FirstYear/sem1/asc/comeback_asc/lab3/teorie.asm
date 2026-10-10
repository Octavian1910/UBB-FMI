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
    a db 1
    b dw 2
    c dd 3

; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        ;PENTRU NUMERE CU SEMN
        
        ;ADC  La suma aduna si CF
        adc eax , ebx
        adc eax, [c]
        adc [c], eax
        adc eax, 5
        adc [c],5
        
        ;SBB La scadere scade si CF
        sbb eax , ebx
        sbb eax , [c]
        sbb [c] , eax
        sbb  eax , 5
        sbb [c] , 5
        
        ;IMUL Inmultire cu semn
        imul bl ; ax = al * bl 
        imul bx ; dx : ax = ax * bx
        imul ebx ; edx:eax = eax * ebx
        
        
        imul byte [a] ; ax = al * a
        imul word [b] ; dx:ax = ax * b
        imul dword [c] ; edx:eax = eax * c
        
        ;IDIV Impartire cu semn
        
        idiv bl ; al = ax / bx ; ah = ax % bx
        idiv bx ; ax = dx:ax / bx ; dx = dx:ax % bx
        idiv ebx ; eax = edx:eax / ebx ; edx = edx : eax % ebx
        
        
        idiv byte [a] ; al = ax / a ; ah = ax % a
        idiv word [b] ; ax = dx:ax / b ; dx = dx : ax % b 
        idiv dword [c] ; eax = edx:eax / c ; eax = edx:eax % c
        
        
        ;CBW  - CONVERT BYTE TO WORD
        
        cbw ; converteste al in ax cu semn
        
        ;CWD - CONVERT WORD TO DWORD
        
        cwd ; / converteste AX in DX:AX cu semn
        
        ;CWDE - CONVERT WORD TO DWORD EXTENDED
        
        cwde ; / converteste AX in EAX cu semn
        
        ;CDQ - Convert DWORD to QWORD
        
        cdq ; - converteste EAX in EDX:EAX cu semn
        
        
        
        
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
