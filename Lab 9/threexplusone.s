;Bikram Kohli
;bsk4uaa
;threexplusone.s

;parameter 1 (in rdi)

	global threexplusone

	section.text

threexplusone:
	xor rax, rax		;zero out return register
	cmp rdi, 1			;base case
	je end
	test rdi, 1 		;checking last bit of register
	jnz odd 			;jump to odd if last bit is not 0
	jz even				;jump to even if last bit is 0

even:
	shr rdi, 1			;num / 2
	call threexplusone	;recursive call
	add rax, 1 			;rax -> 1 + threexplusone(num / 2)
	jmp end				;go to end to return

odd:
	imul rdi, 3			;multiply by 3
	add rdi, 1			;add 1
	call threexplusone	;recursive call
	add rax, 1			;rax -> 1 + threexplusone(3x + 1)
	jmp end				;go to end to return	

end:
	ret 				;return counter