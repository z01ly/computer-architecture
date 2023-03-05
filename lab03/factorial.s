.globl factorial

.data
n: .word 8

.text
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial

    addi a1, a0, 0
    addi a0, x0, 1
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline

    addi a0, x0, 10
    ecall # Exit

factorial:
    # YOUR CODE HERE
    beq a0, x0, special
    addi sp, sp, -4
    sw s0, 0(sp)
    addi s0, a0, -1
loop:
    beq x0, s0, exit
    mul a0, a0, s0
    addi s0, s0, -1
    j loop
exit:
    lw s0, 0(sp)
    addi sp, sp, 4
    jr ra # ret
special:
    addi a0, x0, 1
    jr ra
