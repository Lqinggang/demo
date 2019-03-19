EXECNAME=main
OBJS=base64.o main.o
CC=gcc

TAGS: $(EXECNAME) $(OBJS)
$(EXECNAME):$(OBJS)
	$(CC) -g $(OBJS) -o $(EXECNAME)

%.o:%.c
	$(CC) -g -c $< -o $@

.PHONY:clean
clean:
	rm -rf $(EXECNAME) $(OBJS)
