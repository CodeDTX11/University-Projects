##########################################################################
# Dylan Messerly, CS 2318-002, Assignment 2 Part 1 Program D
##########################################################################
# Prompt user for exam scores
# Multiply exam scores by respective weight and add them together
# Print the labled weighted exam score average to screen 
############################ data segment ################################
			.data

scoreE1Prmt:		.asciiz "Enter exam 1 score: "
scoreE2Prmt:		.asciiz "Enter exam 2 score: "
scoreFinPrmt:		.asciiz "Enter final exam score: "

weightAvgLab:		.asciiz "Your weighted exam average: " 

############################ code segment ################################
			.text
			.globl main
main:
			
			li $v0, 4
			la $a0, scoreE1Prmt
			syscall
			
			li $v0, 5
			syscall
			move $t0, $v0
			
			li $v0, 4
			la $a0, scoreE2Prmt
			syscall
			
			li $v0, 5
			syscall
			move $t1, $v0
			
			li $v0, 4
			la $a0, scoreFinPrmt
			syscall
			
			li $v0, 5
			syscall
			move $t2, $v0		
			
			sll $t0, $t0, 7 	# multiply exam 1 by 128
			
			li $t3, 637		# divide product by 637
			div $t0, $t3
			mflo $t0
			
			li $t3, 307		# multiply exam 2 by 307
			mult $t1, $t3
			mflo $t1
			
			sra $t1, $t1, 10 	# divide product by 1024
			
			sra $t2, $t2, 1 	# divide Final exam by 2
			
			add $t3, $t0, $t1	# add the weighted grades 
			add $t3, $t3, $t2
			
			li $v0, 4
			la $a0, weightAvgLab
			syscall
			
			li $v0, 1
			move $a0, $t3
			syscall
												
			li $v0, 10		# exit
			syscall
