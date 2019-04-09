TARGET= main

SRC= $(wildcard *.c)
OBJS= $(patsubst %.c, %.o, $(SRC))


CC= gcc
CFLAGS= -g
LDFLAGS=

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

.PHONY:clean
clean:
	rm -rf $(TARGET) $(OBJS)
