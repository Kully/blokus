FLAGS = -lSDL2 -lm -flto -O3 -march=native  # release build (FAST)
# FLAGS = -lSDL2 -lm -Og -fsanitize=address     # dev build (SLOW)

all:
	gcc blockus.c lib.c $(FLAGS) -o blockus && ./blockus

clean:
	rm -f blockus
