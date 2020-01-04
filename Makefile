FLAGS = -lSDL2 -lm -flto -O3

all:
	gcc blockus.c lib.c $(FLAGS) -o blockus && ./blockus

clean:
	rm -f blockus
