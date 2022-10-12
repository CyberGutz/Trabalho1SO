
all:
	gcc ./src/main.c -o ./obj/rush.o
	
run:
	gcc ./src/main.c -o ./obj/rush.o
	./obj/rush.o

clean:
	rm ./obj/rush.o