CC = gcc
CFLAGS = 
LDFLAGS = 

.SUFIXES : .c .o
.c .o : 
	$(CC) -c $(CFLAGS) $<

ALL = hello output input args string

all : $(ALL)

hello : hello.o
	$(CC) -o $@ $< $(LDFLAGS)

output: output.o
	$(CC) -o $@ $< $(LDFLAGS)

input: input.o
	$(CC) -o $@ $< $(LDFLAGS)

args: args.o
	$(CC) -o $@ $< $(LDFLAGS)

string: string.o
	$(CC) -o $@ $< $(LDFLAGS)

clean :
	rm -rf *.o $(ALL)
