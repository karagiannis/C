TARGETS = mysqlClient4

CC = gcc

CFLAGS = -Wall -g  -Wpedantic `mysql_config --cflags --libs` 

all: clean $(TARGETS) 

$(TARGETS):
	$(CC) $(CFLAGS) $@.c -o $@

clean:
	rm -f $(TARGETS)
