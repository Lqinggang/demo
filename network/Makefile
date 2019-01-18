OBJS=connect_retry.o initserver.o daemonize.o
CFLAGS=
CC=gcc

TAGS:$(OBJS)
%.o:%.c
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY:clean
clean:
	rm -rf $(OBJS)
