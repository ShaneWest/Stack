CC = gcc
CFLAGS = -o stack
LDFLAGS = -lm

OBJS = stackmain.o stack.o

a.out: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS)

clean: 
	rm $(OBJS) stack
