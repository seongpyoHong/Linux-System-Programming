CC = gcc
CFLAGS =
LDFLAGS = -lpthread

.SUFFIXES : .c .o
.c.o :
	$(CC) -c $(CFLAGS) $<

ALL = sig1 sig2 mysleep alarm nonreent sig_thread cancel

all: $(ALL)

sig1: sig1.o
	$(CC) -o $@ $< $(LDFLAGS)

sig2: sig2.o
	$(CC) -o $@ $< $(LDFLAGS)

mysleep: mysleep.o
	$(CC) -o $@ $< $(LDFLAGS)

alarm: alarm.o
	$(CC) -o $@ $< $(LDFLAGS)

nonreent: nonreent.o
	$(CC) -o $@ $< $(LDFLAGS)

sig_thread: sig_thread.o
	$(CC) -o $@ $< $(LDFLAGS)

cancel: cancel.o
	$(CC) -o $@ $< $(LDFLAGS)

clean :
	rm -rf *.o $(ALL)
