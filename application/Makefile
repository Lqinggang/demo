EXECNAME=server
OBJS=common.o daemonize.o server.o
CFLAGS= -g
CC=gcc

$(EXECNAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@
%.o:%.c
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY:clean
clean:
	rm -rf $(OBJS) $(EXECNAME)
