CC = gcc

CSAPP_INC = ../include
CSAPP_SRC = ../src

CFLAGS = -Wall -O2 -I $(CSAPP_INC) -I .
LDLIBS = -lpthread

PROGS =	echoserveri\
	echoclient\


all: csapp.o $(PROGS)
$(PROGS): csapp.o
csapp.o: csapp.c csapp.h



# Programs that need more than one .o file
echoserveri: echoserveri.o


clean:
	rm -f *.o *~
