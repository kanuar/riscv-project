.data
prices: .word 8,4,6,9,5
size: .word 5
maxprofit: .zero 4

.text
j start
setter:
	mv a0,a3
	j continue

start:
la x1,prices #storing left as x1 as address of prices[0]
lw x2,size #loading size of array
addi x2,x2,-1
slli x2,x2,2
add x2,x1,x2 #storing right as x2 as address of prices[size-1]
li a0,0 # intialising max diff = 0

outerloop:
	mv x3,x2 #creating a copy of the right pointer as the temporary pointer
	lw a1,0(x1)
innerloop:
	lw a2,0(x3)
	bgt a1,a2,continue
	sub a3,a2,a1
	bgt a3,a0,setter
continue: #updating inner loop 
	addi x3,x3,-4
	bne x1,x3,innerloop 
update: #updating outer loop
	addi x1,x1,4
	bne x1,x2,outerloop #loop termination check

sw a0,8(x2) #store result
