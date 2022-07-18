all:
	@gcc -c *.c
	@gcc -o prog *.o

run:
	@./prog

clean:
	@rm *.o prog && clear

val:
	@valgrind ./prog

test: clean all run
