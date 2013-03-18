CC=gcc
MAKE=make
AR=ar

SDIR=src
IDIR=include
TDIR=tests

.PHONY: all clean

all clean sigmund:
	$(MAKE) -C $(SDIR)

