

#machine mode
_start:
andi t0, t0, 0
andi t1, t1, 0

li sp, 0x10010900

la t0, trap_entry
csrw mtvec, t0

li t1, 0x100
csrs medeleg, t1

#setting the MPP bits to 01
li t0, 0x1800
csrrc zero, mstatus, t0 #clearing the MPP bits
li t0, 0x800
csrs mstatus, t0        #setting MPP to 01(supervisor mode)

#setting mepc to S mode code
la t0, s_mode
csrw mepc, t0
mret                    #goes into S mode

#supervisor mode
s_mode:
la t0, strap_entry
csrw stvec, t0

#setting SPP bit to 0
li t0, 0x100
csrc sstatus, t0

#setting sepc to U mode code
la t0, u_mode
csrw sepc, t0
sret                    #goes to U mode

#user mode
u_mode:
#we do an ecall to go to S mode
andi a0, a0, 0
addi a0, a0, 20         #passing a random argument to ecall
ecall

s_mode_cont:
#we are in s mode now until we decide to switch
#to switch, do an ecall
andi a0, a0, 0
addi a0, a0, 21
ecall

m_mode_cont:
#have an infinite loop here
#we are in m mode permanently
li a0, 0x1      #random instruction
j loop

loop: j loop


.p2align 2
trap_entry:
addi sp, sp, -32*8

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
mret

trap_handler:
#checking if it is an interrupt or an exception
csrr t0, mcause
li t1, 0x80000000
and t0, t0, t1
beqz t0, exp_handler
1:  ret

exp_handler:

csrr t0, mcause
li t1, 0x9
and t0, t0, t1
bnez t0, s_ecall_handler

eh_end: j 1b

s_ecall_handler:
# we will take 21 as a signal to switch modes
li t2, 21
beq t2, a0, sw_to_m
j eh_end

sw_to_m:
#setting MPP bits to 11 to stay in machine mode
li t3, 0x1800
csrs mstatus, t3
#setting mepc to m_mode_cont
la t4, m_mode_cont
csrw mepc, t4
j eh_end

.p2align 2
strap_entry:
addi sp, sp, -32*8

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

jal strap_handler

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
sret

strap_handler:
csrr t0, scause
li t1, 0x80000000
and t0, t0, t1
beqz t0, sexp_handler
1:  ret

sexp_handler:
csrr t0, scause
li t1, 0x8
and t0, t0, t1
bnez t0, u_ecall_hdlr

seh_end: j 1b

u_ecall_hdlr:
#20 in a0 means to switch
li t2, 20
beq t2, a0, sw_to_s
j seh_end

sw_to_s:
#setting SPP to 1 to stay in s mode
li t3, 0x100
csrs sstatus, t3
#setting sepc to s_mode_cont to sret to there
la t4, s_mode_cont
csrw sepc, t4
j seh_end





