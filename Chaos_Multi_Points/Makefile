#FLAGS

CC = gcc
GRPH = -lgraph
DBG = -g3
WRN = -Wall

prog : utils.o main.o geometry.o
	$(CC) utils.o main.o geometry.o -o prog $(GRPH) $(WRN) $(DBG)
utils.o : utils.c
	$(CC) -c utils.c $(WRN) $(DBG)
main.o : main.c
	$(CC) -c main.c $(WRN) $(DBG)
geometry.o : geometry.c
	$(CC) -c geometry.c $(WRN) $(DBG)

.PHONY : clean
clean :
	rm -f utils.o main.o geometry.o
