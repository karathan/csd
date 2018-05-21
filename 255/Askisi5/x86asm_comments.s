# -----------------------------------
# Program x86asm.s
# Compute and print the sum 0+...+N
# -----------------------------------
	
	.section .data	# Tells assembler we're in the data segment 
N:	.long 1000	    # long integer / number 1000
S:	.long 0		    # long integer / number 0
Msg:	.ascii "The sum from 0 to %d is %d\n\0"


	.section .text	# Tells assembler we're in the text segment.
.globl main
main:	
	pushl %ebp	    # Pushes the value of ebp onto the stack
	movl %esp, %ebp	# Copy the value of ebp into esp

 	# initialize
    movl N, %ebx	# Move the contents of N(number 1000) into the ebx register

 	# compute sum
L1:
	addl %ebx, S	# ebx = ebx + S 
	decl %ebx       # (decrement long) ebx--
 	cmpl $0, %ebx   # compare 0 with ebx 
	jng  L2	    	# if 0 is less than or equal to ebx jump to the L2
    movl $L1, %eax	# Move L1 into the eax register.Eax= adrress of L1.
    jmp *%eax   	# jump back to L1

L2:
	# print result
	pushl S	    	# push S onto the stack
	pushl N	        # push N onto the stack
	pushl $Msg  	# adrress of msg
	call printf 	# system call for print
	popl %eax   	# pop msg (increment)
	popl %eax   	# pop N
	popl %eax   	# pop S

	# exit
	movl $0, %eax  	# eax = 0
    leave	    	# Set esp to ebp, then pop ebp.
 	ret             # return from call
