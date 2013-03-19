CC=gcc
MAKE=make
AR=ar
LIB=libsigmund.a

CFLAGS=-c -Wall -g
AFLAGS=-rcs

IDIR=../include

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
INC=$(addprefix $(IDIR)/,$(SRC:.c=.h))

.PHONY: all clean

all: sigmund

sigmund: $(OBJ) $(INC)
	$(AR) $(AFLAGS) $(LIB) $<

%.o: %.c $(IDIR)/%.h
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJ)
	rm $(LIB)
