;bikram kohli
;bsk4uaa
;linearSearch.s

	global linearSearch

linearSearch:
	xor rax, rax	;zero out the return register
	dec rax			;-1 in return register (return if val not found)
	xor r10, r10	;zero out the counter i

next:
	cmp r10, rsi 	;does i == n?
	je end			;if so, go to end
	xor r11d, r11d 	;zero out temp
	mov r11d, [rdi + 4 * r10]
	cmp r11d, edx 	;does A[i] == target?
	je found		;target found!
	inc r10			;increment counter
	jmp next 		;start loop over

found:
	mov rax, r10	;put counter into return register
	jmp end			;jump to end to return

end:
	ret 			;return
