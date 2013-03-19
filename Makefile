CC=gcc
MAKE=make
AR=ar
LIB=libsigmund.a

CFLAGS=-c -Wall
AFLAGS=-rcs

SDIR=src
IDIR=include
TDIR=tests
ODIR=obj

SRC=$(wildcard $(SDIR)/*.c)
OBJ=$(addprefix $(ODIR)/,$(notdir $(SRC:.c=.o)))
INC=$(addprefix $(IDIR)/,$(notdir $(SRC:.c=.h)))

.PHONY: all clean

all: sigmund

sigmund: $(OBJ)
	$(AR) $(AFLAGS) $(LIB) $^

$(ODIR)/%.o: $(SDIR)/%.c $(IDIR)/%.h $(ODIR)
	$(CC) $(CFLAGS) $< -o $@

$(ODIR):
	mkdir -p $(ODIR)

clean:
	rm -rf $(ODIR)
	rm $(LIB)
