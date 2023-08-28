OBJ=main.o phone.o tools.o

all:$(OBJ)
	gcc -o tongxunlu $(OBJ)

main.o:main.c phone.h 
	gcc -c main.c
phone.o:phone.c tools.h phone.h
	gcc -c phone.c
tools.o:tools.c tools.h
	gcc -c tools.c

clean:
	rm tongxunlu $(OBJ)
