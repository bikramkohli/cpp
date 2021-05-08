;bikram kohli (bsk4uaa)
;binarySearch.s

;parameters: rdi (arr), rsi (low), rdx (high), rcx (value)

	global binarySearch
	section.text

binarySearch:
	xor rax, rax 		;zero out return register
	dec rax 			;return -1 if value not found
	cmp rdx, rsi		;while(low <= high)
	jl end				;jump to end if not true
	mov r10, rdx		;r10 = high
	add	r10, rsi 		;r10 = low + high
	shr r10, 1			;r10 = (low + high) / 2 -> mid
	mov r11d, [rdi + 4 * r10]
	cmp r11d, ecx		;a[mid] < key?
	jl	low				;jump into first if statement
	cmp r11d, ecx		;a[mid] > key?
	jg 	high			;jump into second if statement
	cmp r11d, ecx		;a[mid] == key?
	je 	match

low:
	mov rsi, r10 		;low = mid
	inc rsi 			;low = mid + 1
	jmp binarySearch	;return to start of loop

high:
	mov rdx, r10 		;high = mid
	dec rdx 			;high = mid - 1
	jmp binarySearch	;return to start of loop

match:
	mov rax, r10		;return index
end:
	ret 				;return
