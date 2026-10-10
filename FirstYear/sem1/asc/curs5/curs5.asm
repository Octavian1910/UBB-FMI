bits 32
global start        
extern exit               
import exit msvcrt.dll    

segment data use32 class=data
sir dq 1122334455667788h, 1a2b3c4d5e6faabbh
lung_sir equ ($ - sir) / 8
r times lung_sir dq 0

segment code use32 class=code
start:
    cld
    mov esi, sir
    lodsb
    lodsw
    lodsd
    mov edi, r
    mov al, 1Ah
    stosb
    mov ax, 1234h
    stosw
    mov eax, 567890cdh
    stosd

    push dword 0
    call [exit]
