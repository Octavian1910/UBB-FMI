bits 32

extern _printf

global _hello_world

segment data public data use32
	mesaj db "Hello Word!",0

segment code public code use32

_hello_world:
	push ebp
	mov ebp,esp
	push mesaj
	call _printf
	add esp,4*1
	pop ebp
	ret
	
	
	
	
