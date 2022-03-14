.data
print_format:
	.string "%d\n"
array:
	.int 238, 42, 134, 168, 4, 85, 219, 171, 182, 15
array_end:

.text
.global main
.type main, @function

main:
	movl $0, %ecx
	movl $array, %ebx
	movl (%ebx), %eax
loop_start:
	and $34, %eax
	cmpl $34, %eax
	jne less
	add (%ebx), %ecx
less:
	addl $4, %ebx
	movl (%ebx), %eax
ch_bound:
	cmpl $array_end, %ebx
	jne loop_start
	
pushl %ecx
pushl $print_format
call printf
addl $8, %esp
movl $0, %ecx
movl $0, %ebx
movl $0, %eax
ret

