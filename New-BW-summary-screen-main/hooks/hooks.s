.align 2
.thumb

.org 0x081344F8
    push {r4, lr}
    ldr r4, =(ShowPokemonSummaryScreen +1)
    bl Linker
    pop {r4, pc}
.pool

Linker:
    bx r4
