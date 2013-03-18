CC=gcc
MAKE=make
AR=ar
LIB=libsigmund.a

CFLAGS=-c -Wall -g
AFLAGS=-rcs

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

.PHONY: all clean

all: sigmund 

sigmund: $(OBJ)
	$(AR) $(AFLAGS) $(LIB) $^

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJ)
	rm $(LIB)
