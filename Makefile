
all:
	clear
	gcc ./src/main.c -o ./obj/rush.o
	
run:
	clear
	gcc ./src/main.c -o ./obj/rush.o
	./obj/rush.o

clean:
	clear
	rm ./obj/rush.o