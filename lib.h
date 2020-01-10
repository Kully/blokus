#pragma once

#include <stdint.h>
#include <stdbool.h>

void setup(void);

void resize(int size);

void lock(void);

void unlock(void);

void shutdown(void);

void delay(int ms);

uint32_t get(int x, int y);

void put(int x, int y, uint32_t pixel);

void line(int x0, int y0, int x1, int y1, uint32_t pixel);

void circle(int x0, int y0, int radius, uint32_t pixel);

void square(int x, int y, int w, int h, uint32_t pixel);

void clear(void);

int UP_KEY(void);

int DOWN_KEY(void);

int LEFT_KEY(void);

int RIGHT_KEY(void);

int Z_KEY(void);

int X_KEY(void);

int C_KEY(void);

int P_KEY(void);

int SPACE_KEY(void);

bool end(void);
