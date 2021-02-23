
ask9: main9.o mods9.o item-implementation.o
	gcc -o ask9 main9.o mods9.o item-implementation.o

main9.o: main9.c
	gcc -c main9.c

mods9.o: mods9.c
	gcc -c mods9.c

item-implementation.o: item-implementation.c
	gcc -c item-implementation.c

clean:
	rm *.o ask9