CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -L. -lmine
TARGET = mycp
OBJS = mycp.o
.SUFFIXES : .c .o
.c.o :
	$(CC) –c $(CFLAGS) $<

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)
clean :
	rm –rf $(TARGET) *.o
