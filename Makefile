#
# Makefile for Shadown88's BHSimulator
#  

#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CC = gcc
CFLAGS  = -g -Wall

all: BHSimulator

BHSimulator:  BHSimulator.o BossLogic.o HeroLogic.o PetLogic.o Logic.o dataBase.o
	$(CC) $(CFLAGS) -o BHSimulator BHSimulator.o BossLogic.o HeroLogic.o PetLogic.o Logic.o dataBase.o

BHSimulator.o:  BHSimulator.c BossLogic.h HeroLogic.h PetLogic.h Logic.h dataBase.h BHSimulator.h
	$(CC) $(CFLAGS) -c BHSimulator.c

BossLogic.o:  BossLogic.c BossLogic.h PetLogic.h Logic.h dataBase.h BHSimulator.h
	$(CC) $(CFLAGS) -c BossLogic.c

HeroLogic.o:  HeroLogic.c HeroLogic.h PetLogic.h Logic.h dataBase.h BHSimulator.h
	$(CC) $(CFLAGS) -c HeroLogic.c

PetLogic.o:  PetLogic.c PetLogic.h dataBase.h BHSimulator.h Logic.h
	$(CC) $(CFLAGS) -c PetLogic.c

Logic.o:  Logic.c Logic.h dataBase.h BHSimulator.h
	$(CC) $(CFLAGS) -c Logic.c

dataBase.o:  dataBase.c dataBase.h BHSimulator.h
	$(CC) $(CFLAGS) -c dataBase.c

clean: 
	$(RM) count *.o *~
