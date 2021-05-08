;Bikram Kohli
;bsk4uaa
;mathlib.s

;parameter 1 (in rdi)
;parameter 2 (in rsi)

	global product
	global power

	section .text

product:
	xor rax, rax	;zero out the return register
	xor r10, r10	;zero out the counter i

start:
	cmp r10, rsi 	;does i == n?
	je done			;if so we are done with the loop
	add rax, rdi	;add rdi to rax
	inc r10			;increment counter
	jmp start		;jump to beginning of loop

done:
	ret 			;return

power:
	mov rax, 1		;1 in the return register

startT:
	cmp rsi, 0 		;base case (power(rdi, 0))
	je doneT		;if so we are done
	dec rsi 		;rsi -= 1
	call power 		;power(rdi, rsi - 1)
	mov rsi, rax	;rsi -> power(rdi, rsi - 1)
	call product 	;rax -> product(rdi, power(rdi, rsi - 1))
doneT:
	ret