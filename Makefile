
all:
	gcc ./src/main.c -o ./obj/rush.o
	
run:
	./obj/rush.o

clean:
	rm ./obj/rush.o