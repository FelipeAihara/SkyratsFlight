.syntax unified
    .cpu    cortex-m4
    .thumb

    .global delayMs
    .type   delayMs, %function

@ R0 = número de milissegundos (parâmetro de entrada, AAPCS)
delayMs:
    MOVS    R1, #0              @ R1 = contador externo (ms decorridos)
    B       LOOP1

LOOP2:
    SUBS    R2, R2, #1          @ decrementa contador interno, atualiza flags
    BPL     LOOP2               @ repete enquanto R2 >= 0
    ADDS    R1, R1, #1          @ terminou 1 "ms": incrementa contador externo

LOOP1:
    MOVW    R2, #27430          @ recarrega contador interno (MOVW aceita 16 bits)
    CMP     R1, R0              @ já passou R0 ms?
    BLT     LOOP2               @ se R1 < R0, faz mais uma volta
    BX      LR                  @ retorna

    .size   delayMs, .-delayMs