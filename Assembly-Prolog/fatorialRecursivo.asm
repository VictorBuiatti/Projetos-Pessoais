# fatorialRecursivo.asm
#
# Programa que lê um número inteiro positivo digitado pelo usuário e retorna o fatorial do mesmo
#
# DDA 08/04/2021
#---------------------------------------------------------------------------------------------------------

.data
     str1: .asciiz "Digite um inteiro positivo: "
     str2: .ascii "\nO fatorial do numero digitado é "
     numero: .word 0
     resultado: .word 0
     
.text
     .globl main
     main:
         # Le o numero digitado pelo usuario
         li $v0, 4
         la $a0, str1
         syscall
         
         li $v0, 5
         syscall
         
         sw $v0, numero
         
         # Chama a função que calcula o fatorial
         lw $a0, numero
         jal calculaFatorial
         sw $v0, resultado     
                   
         # Printa o resultado
         li $v0, 4
         la $a0, str2
         syscall
         
         li $v0, 1
         lw $a0,  resultado
         syscall           
              
	# return 0
	li $v0, 10
	syscall
	
# Função que faz o calculo do fatorial:
.globl calculaFatorial
calculaFatorial: 
               subu $sp, $sp, 8
               sw   $ra, ($sp)
               sw   $s0, 4($sp)
               
               # Caso Base
               li  $v0, 1
               beq $a0, 0, finalizaRecursao
               
               # Caso Recursivo
               move $s0, $a0
               sub  $a0, $a0, 1
               jal  calculaFatorial
               
               # Calculando o fatorial
               mul $v0, $s0, $v0
               
               finalizaRecursao:
                               lw   $ra, ($sp)
                               lw   $s0, 4($sp)
                               addu $sp, $sp, 8
                               jr   $ra



