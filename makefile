CC = gcc
FLAGS= -Wall -Werror -g
add: main run
run: Main
	./$^
main: Main.o client.o
	$(CC) $(FLAGS) $^ -o Main
server: server.o
	$(CC) $(FLAGS) $^ -o server
%.o: %.c
	$(CC) -c $< -o $@
clean:
	rm *.o Main