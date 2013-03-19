CC=gcc
MAKE=make
AR=ar
LIB=libsigmund.a

CFLAGS=-c -Wall
AFLAGS=-rcs

SDIR=src
IDIR=include
TDIR=tests

SRC=$(wildcard $(SDIR)/*.c)
OBJ=$(SRC:.c=.o)
INC=$(addprefix $(IDIR)/,$(notdir $(SRC:.c=.h)))

.PHONY: all clean

all: sigmund

sigmund: $(OBJ)
	$(AR) $(AFLAGS) $(LIB) $^

$(SDIR)/%.o: $(SDIR)/%.c $(IDIR)/%.h
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJ)
	rm $(LIB)
