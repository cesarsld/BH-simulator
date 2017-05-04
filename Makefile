TARGET = bin/BHSimulator.o
CC = gcc
CFLAGS = -Ofast -g -Wall

.PHONY: default clean

OBJECTS = $(patsubst %.c, %.o, $(wildcard src/*.c))
HEADERS = $(wildcard src/*.h)

%.o: %.c $(HEADERS)#
	@$(CC) $(CFLAGS) -c $< -o $@


$(TARGET): $(OBJECTS)
	@echo "Compiling BHSimulation.."
	@mkdir -p bin
	@$(CC) src/main/main.c $(OBJECTS) $(LIBS) $(CFLAGS) -o $@
	@echo "BHSimulation compiled with" $(CFLAGS)

clean:
	@-rm -f src/*.o
	@-rm -f $(TARGET)
