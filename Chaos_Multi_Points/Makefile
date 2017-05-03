#FLAGS

CC = gcc
GRPH = -lgraph
DBG = -g3
WRN = -Wall

prog : utils.o main.o
	$(CC) utils.o main.o -o prog $(GRPH) $(WRN) $(DBG)
utils.o : utils.c
	$(CC) -c utils.c $(WRN) $(DBG)
main.o : main.c
	$(CC) -c main.c $(WRN) $(DBG)
.PHONY : clean
clean :
	rm -f utils.o main.o
