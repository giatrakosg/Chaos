#FLAGS

CC = gcc
GRPH = -lgraph
DBG = -g3
WRN = -Wall

chaos_triangle : utils.o chaos_triangle.o
	$(CC) utils.o chaos_triangle.o -o chaos_triangle $(GRPH) $(WRN) $(DBG)
utils.o : utils.c
	$(CC) -c utils.c $(WRN) $(DBG)
chaos_triangle.o : chaos_triangle.c
	$(CC) -c chaos_triangle.c $(WRN) $(DBG)
.PHONY : clean
clean :
	rm -f utils.o chaos_triangle.o chaos_triangle
