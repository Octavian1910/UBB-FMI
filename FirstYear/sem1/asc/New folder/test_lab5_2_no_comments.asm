; Se dau doua cuvinte A si B. Sa se obtina dublucuvantul C:
; bitii 0-6 ai lui C au valoarea inversului bitilor 2-8 ai lui A
; bitii 7-9 ai lui C coincid cu bitii 0-2 ai lui A
; bitii 10-15 ai lui C coincid cu bitii 8-13 ai lui B
; bitii 16-31 ai lui C au valoarea 1

; Dupa crearea dublucuvantului C, quadwordul D va avea valoarea urmatoarei expresii in interpretarea cu semn:
;d = [(a/b + c) / 2] - (c*a)
bits 32
global  start

extern  exit
import  exit msvcrt.dll

segment  data use32 class=data
a dw 0110001110110101b ;00h 00h word ax
b dw 1010000100110110b
c dd 0
d dq 0
temp dw 0
segment  code use32 class=code
start:
    MOV eax, 0  ;eax = 00h00h 00h00h
    mov ebx, 0  ;ebx = 0000 0000h
    
; bitii 0-6 ai lui C au valoarea inversului bitilor 2-8 ai lui A
 
    mov bx, [a]             ; bx = 0110001110110101b
                                         ;876543210
    and bx, 111111100b      ; bx = 0110001110110101b
                            ;             111111100b
                            ; bx = 0000000110110100b
                                         ;876543210
    not bx                  ; bx = 1111111001001011b
    ;SHL bx, 2              ;Gresit trebuie sa fie mutam spre dreapta si 2 trb pus in Cl
     mov cl,2
     SHR bx,cl                            ;876543210
                            ; bx = 0011111110010010b
    OR eax, ebx             ; eax =0000000000000000 0000000000000000b
                            ; ebx =0000000000000000 1111100100101100b
                            ; eax= 0000000000000000 1111100100101100b
                                                          ;876543210
                                                            ;6543210 doar atat ne ar trebui
    ;TREBUIE SA FACEM AH = 0                                    6543210
    mov AH,0                ; eax= 0000000000000000 0000.0000.0010.1100b
    ; bitii 7-9 ai lui C coincid cu bitii 0-2 ai lui A         
    mov ebx, 0             ; ebx = 0000000000000000 0000000000000000b
    mov bx, [a]            ; bx =  0110001110110101b
    
    and bx, 111b           ; bx =  0110001110110101b
                           ;                   111b
                           ; bx =  0000000000000101b
                                                ;210
    ;ROL bx, 7              ; trebuie ca 7 sa fie pus in cl
    mov cl,7
    ROL bx, cl              ; bx = 0000001010000000b
                                        ;9876543210
 
    or eax, ebx             ; eax = 0000000000000000 0000000000101100b
                            ; ebx = 0000000000000000 0000001010000000b
                            ; eax=  0000000000000000 0000001010101100b
                                                          ;9876543210
                                                          
; bitii 10-15 ai lui C coincid cu bitii 8-13 ai lui B
                                      ;32109876543210
    mov bx, [b]              ;  bx = 1010000100110110b
    ;SHR bx, 8               ;  bx = 0000000010100001b Gresit trebuia sa mearga doar 2 pozitii spre stanga
    mov cl,2                 
                                      ;32109876543210
    SHL bx,cl                ;  bx = 1000010011011000b
    
    ;and bx, 111111b          ;  bx =  gresit trb and pt bitii  10 - 15
    and bx, 1111110000000000b  ; bx =  1000010011011000b
                                      ;1111110000000000b
                                      ;1000010000000000b
                            
    SHL bx, 10              
    or eax, bx
    mov bx, -1
    SHL ebx, 16
    OR eax, ebx
    mov [c], ax
    mov ax, [a]
    cwd
    idiv [b]
    cwd
    adc ax, [c]
    adc dx, [c+4]
    div 2
    mov [temp], ax
    mov ebx, [c]
    mov ax, [a]
    cwd ax, eax
    imul eax
    mov ebx, eax
    mov ecx, edx
    mov eax, 0
    mov ax, [temp]
    cdq
    sub eax, ebx
    sbb edx, ecx
    mov [d], eax
    mov [d+4], edx
    
    
    push dword 0
    call [exit]
