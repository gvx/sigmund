CC=gcc
AR=ar

OBJDIR=bin
SRCDIR=src
SRCS=$(wildcard $(SRCDIR)/*.c)
OBJS=$(SRCS:.c=.o)
