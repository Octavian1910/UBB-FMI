use 32

segment data use32 class=data
    format db "%s",13,10,0


segment code use32 public code
global baza2:

;baza2(sir,len)
baza2:
    mov ebx,[esp+4] ;len 
    mov esi,[esp+8] ;sir
    
    
    
    
    ret 4*2