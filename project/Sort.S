_start:
la t0,_data1
lw x1,0(t0)	
addi x2,t0,4	#array pointer in x2
srai x17, x0,1
srai x12, x0,1
addi x7, x2,0			#pointer to the array
_start1 :
				#start of for loop
	srai x12, x0,1
	addi x7, x2,0
		sub x9,x1,x17
		addi x9,x9,-1
		bge x12,x9,_end2	
		_start2 :
					#start of second for loop
			lw x5, 0(x7)
			lw x6, 4(x7)
			ble x5,x6, _end1	#if a[j]>a[j+1]
			sw x6, 0(x7)	#swapping
			sw x5,4(x7)
		_end1:
	addi x7,x7,4
	addi x12,x12,1
	sub x9,x1,x17
	addi x9,x9,-1
	blt x12,x9,_start2
	_end2:
	addi x17,x17,1
	blt x17,x1,_start1		
ebreak
j  _start
	.section .data
	.p2align 0x2 
	_data1:
	.word 0x5	#no of inputs
	.word 0x5	#array start
        .word 0x4
	.word 0x3
	.word 0x2
	.word 0x1
