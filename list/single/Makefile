EXECNAME=main
OBJS=list.o main.o
CC=gcc
CFLAGS= -g -D LEADNODE
LINK=

$(EXECNAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXECNAME) $(LINK)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LINK)

.PHONY:clean
clean:
	rm -rf $(EXECNAME) $(OBJS)
