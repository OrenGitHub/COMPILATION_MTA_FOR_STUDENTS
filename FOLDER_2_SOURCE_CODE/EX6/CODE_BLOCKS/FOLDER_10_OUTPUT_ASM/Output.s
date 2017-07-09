main:

jal Label_0_main

Label_0_main:

	addi $fp,$sp,40

	li $t0,-4

	add $t0,$fp,$t0

	addi $sp,$sp,-4

	sw $t0,0($sp)

	addi $sp,$sp,-4

	sw $t1,0($sp)

	addi $sp,$sp,-4

	sw $t2,0($sp)

	addi $sp,$sp,-4

	sw $t3,0($sp)

	addi $sp,$sp,-4

	sw $t4,0($sp)

	addi $sp,$sp,-4

	sw $t5,0($sp)

	addi $sp,$sp,-4

	sw $t6,0($sp)

	addi $sp,$sp,-4

	sw $t7,0($sp)

	li $t0,33

	addi $sp,$sp,-4

	sw $t0,0($sp)

	li $t0,6701

	addi $sp,$sp,-4

	sw $t0,0($sp)

	li $t0,2

	addi $sp,$sp,-4

	sw $t0,0($sp)

	jal Label_1_AllocateRecord

	addi $sp,$sp,12

	lw $t7,0($sp)

	addi $sp,$sp,4

	lw $t6,0($sp)

	addi $sp,$sp,4

	lw $t5,0($sp)

	addi $sp,$sp,4

	lw $t4,0($sp)

	addi $sp,$sp,4

	lw $t3,0($sp)

	addi $sp,$sp,4

	lw $t2,0($sp)

	addi $sp,$sp,4

	lw $t1,0($sp)

	addi $sp,$sp,4

	lw $t0,0($sp)

	addi $sp,$sp,4

	sw $v0,0($t0)

	addi $sp,$sp,-4

	sw $t0,0($sp)

	addi $sp,$sp,-4

	sw $t1,0($sp)

	addi $sp,$sp,-4

	sw $t2,0($sp)

	addi $sp,$sp,-4

	sw $t3,0($sp)

	addi $sp,$sp,-4

	sw $t4,0($sp)

	addi $sp,$sp,-4

	sw $t5,0($sp)

	addi $sp,$sp,-4

	sw $t6,0($sp)

	addi $sp,$sp,-4

	sw $t7,0($sp)

	li $t0,734

	addi $sp,$sp,-4

	sw $t0,0($sp)

	jal Label_3_PrintInt

	addi $sp,$sp,4

	lw $t7,0($sp)

	addi $sp,$sp,4

	lw $t6,0($sp)

	addi $sp,$sp,4

	lw $t5,0($sp)

	addi $sp,$sp,4

	lw $t4,0($sp)

	addi $sp,$sp,4

	lw $t3,0($sp)

	addi $sp,$sp,4

	lw $t2,0($sp)

	addi $sp,$sp,4

	lw $t1,0($sp)

	addi $sp,$sp,4

	lw $t0,0($sp)

	addi $sp,$sp,4

	li $v0,10

	syscall
Label_1_AllocateRecord:

	lw $a0,0($sp)

	li $a1,4

	mul $a0,$a1,$a0

	li $v0,9

	syscall

	lw $a0,0($sp)

	li $a1,0

	li $a2,0

Label_1_Loop:

	bge $a1,$a0,Label_1_ExitLoop

	add $v1,$v0,$a2

	addi $a3,$sp,4

	add $a3,$a3,$a2

	lw $a3,0($a3)

	sw $a3,0($v1)

	addi $a1,$a1,1

	addi $a2,$a2,4

	j Label_1_Loop

Label_1_ExitLoop:

	jr $ra

Label_2_AllocateArray:

	lw $a0,0($sp)

	addi $a0,$a0,1

	li $a1,4

	mul $a0,$a1,$a0

	li $v0,9

	syscall

	lw $a0,0($sp)

	sw $a0,0($v0)

	li $a1,0

	li $a2,0

Label_2_Loop:

	bge $a1,$a0,Label_2_ExitLoop

	add $v1,$v0,$a2

	addi $v1,$v1,4

	lw $a3,4($sp)

	sw $a3,0($v1)

	addi $a1,$a1,1

	addi $a2,$a2,4

	j Label_2_Loop

Label_2_ExitLoop:

	jr $ra

Label_3_PrintInt:

	lw $a0,0($sp)

	li $v0,1

	syscall

	li $a0,32

	li $v0,11

	syscall

	jr $ra

Label_4_Access_Violation:

	li $a0,65

	li $v0,11

	syscall

	li $a0,99

	li $v0,11

	syscall

	li $a0,99

	li $v0,11

	syscall

	li $a0,101

	li $v0,11

	syscall

	li $a0,115

	li $v0,11

	syscall

	li $a0,115

	li $v0,11

	syscall

	li $a0,32

	li $v0,11

	syscall

	li $a0,86

	li $v0,11

	syscall

	li $a0,105

	li $v0,11

	syscall

	li $a0,111

	li $v0,11

	syscall

	li $a0,108

	li $v0,11

	syscall

	li $a0,97

	li $v0,11

	syscall

	li $a0,116

	li $v0,11

	syscall

	li $a0,105

	li $v0,11

	syscall

	li $a0,111

	li $v0,11

	syscall

	li $a0,110

	li $v0,11

	syscall

	li $v0,10

	syscall

