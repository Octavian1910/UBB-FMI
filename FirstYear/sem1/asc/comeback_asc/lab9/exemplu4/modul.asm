bits32

global _factorial

segment data public data use32

segment code public code use32

_factorial:
	push ebp
	mov ebp,esp
	cmp [ebp,8],2
	jbe .trivial
	
	
	.recursiv
	  dec eax
	  push eax
	  call _factorial
          add esp,4
	  mov [ebp-4],eax   ; m = (n-1)!
          mov eax,[ebp+8]
	  mul dword [ebp-4]
          jmp .final
	
	.trivial:
		xor edx,edx
	.final:
	add esp,4

	mov esp,ebp
	pop ebp
	ret
	