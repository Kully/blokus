#pragma once

#include <stdint.h>
#include <stdbool.h>

void setup(void);

void resize(int size);

void lock(void);

void unlock(void);

void shutdown(void);

void delay(int ms);

void point(int x, int y, uint32_t pixel);

void line(int x0, int y0, int x1, int y1, uint32_t pixel);

void circle(int x0, int y0, int radius, uint32_t pixel);

void square(int x, int y, int w, int h, uint32_t pixel);

void clear(void);

bool end(void);
