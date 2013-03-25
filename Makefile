CC=gcc
MAKE=make
AR=ar
LIB=libsigmund.a
TEST=sigtest

CFLAGS=-c -Wall -g -std=c99
LFLAGS=-L. -lsigmund
AFLAGS=-rcs

SDIR=src
IDIR=include
TDIR=tests
ODIR=obj

SRC=$(wildcard $(SDIR)/*.c)
TSRC=$(wildcard $(TDIR)/*.c)
OBJ=$(addprefix $(ODIR)/,$(notdir $(SRC:.c=.o)))
TOBJ=$(addprefix $(TDIR)/,$(notdir $(TSRC:.c=.o)))
INC=$(addprefix $(IDIR)/,$(notdir $(SRC:.c=.h)))

.PHONY: all clean testclean

all: sigmund

sigmund: $(OBJ)
	$(AR) $(AFLAGS) $(LIB) $^

$(ODIR)/%.o: $(SDIR)/%.c $(IDIR)/%.h $(ODIR)
	$(CC) $(CFLAGS) $< -o $@

$(ODIR):
	mkdir -p $(ODIR)

test: $(TOBJ)
	gcc $^ $(LFLAGS) -o $(TDIR)/$@

$(TDIR)/%.o: $(TDIR)/%.c
	gcc $(CFLAGS) $< -o $@

clean:
	rm -rf $(ODIR)
	rm $(LIB)

testclean:
	rm tests/test
	rm $(TDIR)/*.o
