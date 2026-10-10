; Se dau cuvintele A si B. Se cere cuvantul C format astfel:
;- bitii 0-2 ai lui C coincid cu bitii 10-12 ai lui B
;- bitii 3-6 ai lui C au valoarea 1
;- bitii 7-10 ai lui C coincid cu bitii 1-4 ai lui A
;- bitii 11-12 ai valoarea 0
;- bitii 13-15 ai lui C concid cu inverul bitilor 9-11 ai lui B

; Vom obtine cuvantul C prin operatii succesive de "izolare". Numim operatia
; de izolare a bitilor 10-12 ai lui B, pastrarea intacta a valorii acestor
; biti, si initializarea cu 0 a celorlalti biti. Operatiunea de izolare se
; realizeaza cu ajutorul operatorului and intre cuvantul B si masca
; 0001110000000000. Odata bitii izolati, printr-o operatie de rotire se
; deplaseaza grupul de biti doriti in pozitia dorita. Cuvantul final se
; obtine prin aplicarea operatorului or intre rezultatele intermediare
; obtinute in urma izolarii si rotirii.
; Observatie: rangul bitilor se numara de la dreapta la stanga

bits 32 ;asamblare si compilare pentru arhitectura de 32 biti
; definim punctul de intrare in programul principal
global  start 

extern  exit ; indicam asamblorului ca exit exista, chiar daca noi nu o vom defini
import  exit msvcrt.dll; exit este o functie care incheie procesul, este definita in msvcrt.dll
        ; msvcrt.dll contine exit, printf si toate celelalte functii C-runtime importante
segment  data use32 class=data ; segmentul de date in care se vor defini variabilele 
     a dw 0111011101010111b
     b dw 1001101110111110b
     c dw 0
segment  code use32 class=code ; segmentul de cod
start: 

        mov bx,0 ; in bx tinem rezultatul
        ;;- bitii 0-2 ai lui C coincid cu bitii 10-12 ai lui B
                         
        mov ax,0001110000000000b
        and ax,[b]
        mov cl,10
        shr ax,cl
        or bx,ax
        
        ;- bitii 3-6 ai lui C au valoarea 1
        or bx,00000000001111000b
        
        ;- bitii 7-10 ai lui C coincid cu bitii 1-4 ai lui A
        
        mov ax , [a]
        and ax, 00000000000011110b
        
        mov cl,6
        shl ax,cl
        or bx,ax
        
        ;- bitii 11-12 ai valoarea 0
        and bx,11100111111111111b
        
        ;- bitii 13-15 ai lui C concid cu inverul bitilor 9-11 ai lui B
        
        mov ax,[b]
        not ax
        and ax,000011100000000b
        mov cl,2
        shr ax,cl
        or bx,ax
        
        mov [c],bx
        
        
    
     push dword 0 ;se pune pe stiva codul de retur al functiei exit
     call [exit] ;apelul functiei sistem exit pentru terminarea executiei programului	
