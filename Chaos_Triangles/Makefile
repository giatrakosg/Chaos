#FLAGS

CC = gcc
GRPH = -lgraph
DBG = -g3
WRN = -Wall

Chaos_triangle : utils.o chaos_triangle.o
	$(CC) utils.o chaos_triangle.o -o Chaos_triangle $(GRPH) $(WRN) $(DBG)
utils.o : utils.c
	$(CC) -c utils.c $(WRN) $(DBG)
chaos_triangle.o : chaos_triangle.c
	$(CC) -c chaos_triangle.c $(WRN) $(DBG)
