FLAGS = -lSDL2 -lm -flto -O3 -mcpu=apple-a14  # release build (MAC)
# FLAGS = -lSDL2 -lm -flto -O3 -march=native  # release build (FAST)
# FLAGS = -lSDL2 -lm -Og -fsanitize=address     # dev build (SLOW)

all:
	gcc src/main.c src/io.c $(FLAGS) -o blokus && ./blokus

clean:
	rm -f blokus
