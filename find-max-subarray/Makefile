CC=gcc

main:main.o
	$(CC) -g $^ -o $@
main.o:main.c
	$(CC) -g -c $^ -o $@
.PHONY:clean
clean:
	rm -rf main.o main
