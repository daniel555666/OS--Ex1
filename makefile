CC = gcc
FLAGS= -Wall -Werror -g
add: main run
run: Main
	./$^
main: Main.o
	$(CC) $(FLAGS) $^ -o Main
%.o: %.c
	$(CC) -c $< -o $@
clean:
	rm *.o Main