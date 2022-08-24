##########################################################################
# Dylan Messerly, CS 2318-002, Assignment 2 Part 1 Program C
##########################################################################
# First displays the initial array from elements 1 to 4
# Swaps array elements 1 and 4 then swaps array elements 2 and 3
# Displays the new swapped array in reverse order from 4 to 1
############################ data segment ################################
			.data

intArray:		.word 8, 1, 3, 2
initialArrLab:		.asciiz "Initial array: "
finalArrLab:		.asciiz "Final array: "


############################ code segment ################################
			.text
			.globl main
main:

			li $v0, 4		# Labled output for the initial 
			la $a0, initialArrLab	# array from elements 1 to 4
			syscall 
			
			la $t0, intArray
			lw $a0, 0($t0)
			li $v0, 1
			syscall
			li $v0, 11
			li $a0, ' '
			syscall
			lw $a0, 4($t0)
			li $v0, 1
			syscall
			li $v0, 11
			li $a0, ' '
			syscall
			lw $a0, 8($t0)
			li $v0, 1
			syscall
			li $v0, 11
			li $a0, ' '
			syscall
			lw $a0, 12($t0)
			li $v0, 1
			syscall
			li $v0, 11
			li $a0, '\n'
			syscall

			lw $t1, 0($t0)		# Reloading words from memory
			lw $t2, 4($t0)
			lw $t3, 8($t0)
			lw $t4, 12($t0)
			
			sw $t1, 12($t0) 	# Swapping elements 1 and 4
			sw $t4, 0($t0)
			
			sw $t2, 8($t0) 		# Swapping elemnts 2 and 3
			sw $t3, 4($t0)
			
			li $v0, 4
			la $a0, finalArrLab
			syscall 
			
			lw $a0, 12($t0) 	# Labeled output for the swapped 
			li $v0, 1		# array from element 4 to 1
			syscall
			li $v0, 11
			li $a0, ' '
			syscall
			lw $a0, 8($t0)
			li $v0, 1
			syscall
			li $v0, 11
			li $a0, ' '
			syscall
			lw $a0, 4($t0)
			li $v0, 1
			syscall
			li $v0, 11
			li $a0, ' '
			syscall
			lw $a0, 0($t0)
			li $v0, 1
			syscall
			li $v0, 11
			li $a0, '\n'
			syscall
			
			li $v0, 10		# exit
			syscall
