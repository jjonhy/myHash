all: montador simulador

montador:
	./montador_fonte/montador myHash.asm myHash.mif

simulador:
	./simulador_fonte/sim myHash.mif charmap.mif

