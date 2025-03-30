CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -static


top: child_test icount
child_test: child_test.o
icount: icount.o



.PHONY: clean
clean:
	rm ./*.o icount


.PHONY: all
all: clean top
