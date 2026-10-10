bits 32

global _sum
segment data public data use32
segment code public code use32
_sum:
	push ebp
	mov ebp, esp	                   	
	mov eax, [ebp+8]
	add eax, [ebp+12]  
	mov esp, ebp
	pop ebp
    ret