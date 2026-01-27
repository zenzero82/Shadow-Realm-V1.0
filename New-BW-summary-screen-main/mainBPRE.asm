.gba
.thumb
.open "BPRE.gba","build/rom_BPRE.gba", 0x08000000
//---------------------------------------------------

//hooks
.include "hooks/hooks.s"

.align 4
.org insertinto
.importobj "build/linked.o"
.close
