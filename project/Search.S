_start:
	la    t0, _data1
	lw   sp, 0(x5)
	addi a0,t0,12
	    			
        mv    a1,x0
				#setting arguments
	lw a2,4(t0)
	addi a2,a2,-1

	lw a3,8(t0)

	addi t4,x0,4
	addi t5,x0,2
        jal ra,_search
	
	#return value stored in a7
ebreak
j  _start

_search:
	addi  sp,sp,-32
	sw    ra,24(sp)
	blt a2,a1,_J1
	add t1,a1,a2
	div t1,t1,t5
	mul t1,t1,t4
	add t3,t1,a0
	lw t2,0(t3)
	beq t2,a3,_J2
	blt t2,a3,_J3
			#if a[mid]>x
	div t1,t1,t4
	addi a2,t1,-1
	jal ra,_search
	lw ra,24(sp)
	addi sp,sp,32
	ret
	
_J1: 			#if start<end means element is not there in array

	addi a7,x0,-1
	lw ra,24(sp)
	addi sp,sp,32
	ret
_J2: 			#if a[mid]==x

	div t1,t1,t4
	add a7,x0,t1	#return value storing in a7
	lw ra,24(sp)
	addi sp,sp,32
	ret
_J3: 			#if a[mid]<x

	div t1,t1,t4
	addi a1,t1,1	#return value storing in a7;
	jal ra,_search
	lw ra,24(sp)
	addi sp,sp,32
	ret

	.section .data
	.p2align 0x2 
	_data1:
	.word 0x10011000
	.word 0x5	#no of inputs
	.word 0x5	#find 
	.word 0x1	#array start
        .word 0x2
	.word 0x3
	.word 0x4
	.word 0x5
