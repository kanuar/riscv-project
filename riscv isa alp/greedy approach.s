.data
ary: .word 7, 1, 5, 3, 6, 4
size: .word 6
profit: .zero 4

.text
j start

movesub:
    mv a0,a1
    j callback

movemax:
    mv s0,a2
    j continue

start:
    li s0,0 #storing maximum as 0 initially
    la x1,ary #loading address of array[0]
    la x2,size 
    lw x2,0(x2) #loading size of array
    la x3,profit 
    addi x2,x2,-1 #len-1 
    lw a0,0(x1) #sub pointer
loop:
    lw a1,4(x1) #cur pointer
    bge a0,a1,movesub
callback:
    sub a2,a1,a0 #calc diff
    bgt a2,s0,movemax
continue:
    addi x1,x1,4
    addi x2,x2,-1
    bne x2,x0,loop

ender: # to store final result
    sw s0,0(x3)
