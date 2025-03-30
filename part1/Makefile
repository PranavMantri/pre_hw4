# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g
LFLAGS = -nostdlib -nodefaultlibs -static

# Targets
TARGETS = icount child_test

# Source files for each target
ICOUNT_SRCS = icount.c 
CHILD_TEST_SRCS = child_test.c

# Object files for each target
ICOUNT_OBJS = $(ICOUNT_SRCS:.c=.o)
CHILD_TEST_OBJS = $(CHILD_TEST_SRCS:.c=.o)

# Default target to build both programs
all: $(TARGETS)

# Build icount
icount: $(ICOUNT_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Build child_test
child_test: $(CHILD_TEST_OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ $^

# Compiling individual source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(ICOUNT_OBJS) $(CHILD_TEST_OBJS) $(TARGETS)

# Phony targets to avoid conflict with files named 'clean' or 'all'
.PHONY: all clean

