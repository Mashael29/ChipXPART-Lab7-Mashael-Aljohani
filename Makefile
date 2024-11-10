CC=gcc
CFLAGS = -Wall 
SOURCES = Task1.c Task2.c Task3.c Task4.c Task5.c
EXES = Task1 Task2 Task3 Task4 Task5

all: $(EXES)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean: 
	rm -f $(EXES)
