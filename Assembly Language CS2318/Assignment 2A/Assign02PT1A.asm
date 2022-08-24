### Dylan Messerly, CS 2318-002, Assignment 2 Part 1 Program A

### Program Description ###########################################
# Prompt the user to input an integer then display the integer
# Prompt the user to input a string of up to 50 characters 
# maxium then display the string
# Prompt the user to input a single character then display 
# the character
###################################################################

				.data
string:				.space 51
intPrmpt: 			.asciiz "Enter an integer: "
intLab: 			.asciiz "Your integer is: "
strPrmpt:			.asciiz "Enter a string: "
strLab: 			.asciiz "Your string is: "
chrPrmpt:			.asciiz "Enter a single character: "
chrLab:				.asciiz "Your character is: "

###################################################################

				.text
				.globl main
main:
				li $v0, 4
				la $a0, intPrmpt
				syscall
				
				li $v0, 5
				syscall
				move $t0, $v0
				
				li $v0, 4
				la $a0, intLab
				syscall
				
				li $v0, 1
				move $a0, $t0
				syscall
				
				li $v0, 11
				li $a0, '\n'
				syscall
				
				li $v0, 4
				la $a0, strPrmpt
				syscall
				
				li $v0, 8
				la $a0, string
				li $a1, 51
				syscall
																										
				li $v0, 4
				la $a0, strLab
				syscall
				
				li $v0, 4
				la $a0, string
				syscall
				
				li $v0, 4
				la $a0, chrPrmpt
				syscall
				
				li $v0, 12
				syscall
				move $t0, $v0
				
				li $v0, 11
				li $a0, '\n'
				syscall
				
				li $v0, 4
				la $a0, chrLab
				syscall
				
				li $v0, 11
				move $a0, $t0
				syscall
				
				li $v0, 11
				li $a0, '\n'
				syscall
											
				li $v0, 10
				syscall				
