
ask10: main10.o mods10.o item-implementation.o
	gcc -o ask10 main10.o mods10.o item-implementation.o

main10.o: main10.c
	gcc -c main10.c

mods10.o: mods10.c
	gcc -c mods10.c

item-implementation.o: item-implementation.c
	gcc -c item-implementation.c

clean:
	rm *.o ask10