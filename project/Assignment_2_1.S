start:
lui sp,0x10011
la t0,trap_entry
csrw mtvec,t0




#environment call from m mode mcause = 11
ecall
#store address misaligned mcause = 6
la x15,_data1
sw x17,0(x15)
#load access fault mcause = 5
lui t0,0xfffff
lw t1,0(t0)
#store access fault mcause = 7
lui t0,0xfffff
sw x0,0(t0)
#load address misaligned mcause = 4
la x15,_data1
lw x17,0(x15)




trap_handler:
csrr t0,mepc
sd t0,32*8(sp)
addi t0,t0,4
csrw mepc,t0
csrr t0,mcause
sd t0,33*8(sp)
ret









.p2align 2
trap_entry:     
addi sp, sp, -34*8
 #x0 is always 0
sd x1, 1*8(sp)
sd x2, 2*8(sp)
sd x3, 3*8(sp)
sd x4, 4*8(sp)
sd x5, 5*8(sp)
sd x6, 6*8(sp)
sd x7, 7*8(sp)
sd x8, 8*8(sp)
sd x9, 9*8(sp)
sd x10, 10*8(sp)
sd x11, 11*8(sp)
sd x12, 12*8(sp)
sd x13, 13*8(sp)
sd x14, 14*8(sp)
sd x15, 15*8(sp)
sd x16, 16*8(sp)
sd x17, 17*8(sp)
sd x18, 18*8(sp)
sd x19, 19*8(sp)
sd x20, 20*8(sp)
sd x21, 21*8(sp)
sd x22, 22*8(sp)
sd x23, 23*8(sp)
sd x24, 24*8(sp)
sd x25, 25*8(sp)
sd x26, 26*8(sp)
sd x27, 27*8(sp)
sd x28, 28*8(sp)
sd x29, 29*8(sp)
sd x30, 30*8(sp)
sd x31, 31*8(sp)

jal trap_handler

ld x1, 1*8(sp)
ld x2, 2*8(sp)
ld x3, 3*8(sp)
ld x4, 4*8(sp)
ld x5, 5*8(sp)
ld x6, 6*8(sp)
ld x7, 7*8(sp)
ld x8, 8*8(sp)
ld x9, 9*8(sp)
ld x10, 10*8(sp)
ld x11, 11*8(sp)
ld x12, 12*8(sp)
ld x13, 13*8(sp)
ld x14, 14*8(sp)
ld x15, 15*8(sp)
ld x16, 16*8(sp)
ld x17, 17*8(sp)
ld x18, 18*8(sp)
ld x19, 19*8(sp)
ld x20, 20*8(sp)
ld x21, 21*8(sp)
ld x22, 22*8(sp)
ld x23, 23*8(sp)
ld x24, 24*8(sp)
ld x25, 25*8(sp)
ld x26, 26*8(sp)
ld x27, 27*8(sp)
ld x28, 28*8(sp)
ld x29, 29*8(sp)
ld x30, 30*8(sp)
ld x31, 31*8(sp)

addi sp, sp, 32*8
mret


_data1:
.word 	7
