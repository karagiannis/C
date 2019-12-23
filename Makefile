TARGETS = testpointer1

CC = gcc

CFLAGS = -Wall -g  -Wpedantic  

all: clean $(TARGETS) 

$(TARGETS):
	$(CC) $(CFLAGS) $@.c -o $@

clean:
	rm -f $(TARGETS)
