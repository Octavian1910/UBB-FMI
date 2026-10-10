bits 32                         
segment code use32 public code
global calcul

;calcul(a,b,c)
calcul:
;Se cere se se citeasca numerele a, b si c ; sa se calculeze si sa se afiseze a+b-c.
    mov eax,[esp+4]
    mov ebx,[esp+8]
    mov ecx,[esp+12]
    add eax,ebx
    sub eax,ecx
    ret
