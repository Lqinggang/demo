EXECNAME=main
OBJS=list.o main.o
CC=gcc
CFLAGS= -g
LINK=

TAGS:$(EXECNAME) $(OBJS)
$(EXECNAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXECNAME)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:clean
clean:
	rm -rf $(OBJS) $(EXECNAME)
