FLAGS = -lSDL2 -lm -flto -O3 -march=native  # release build (FAST)
# FLAGS = -lSDL2 -lm -Og -fsanitize=address     # dev build (SLOW)

all:
	gcc src/blokus.c src/lib.c $(FLAGS) -o blokus && ./blokus

clean:
	rm -f blokus
