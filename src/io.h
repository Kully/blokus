#pragma once

#include <stdint.h>
#include <stdbool.h>

void io_setup(void);

void io_resize(int size);

void io_lock(void);

void io_unlock(void);

void io_shutdown(void);

void io_delay(int ms);

uint32_t io_get(int x, int y);

void io_put(int x, int y, uint32_t pixel);

void io_line(int x0, int y0, int x1, int y1, uint32_t pixel);

void io_circle(int x0, int y0, int radius, uint32_t pixel);

void io_square(int x, int y, int w, int h, uint32_t pixel);

void io_clear(void);

int io_up_key(void);

int io_down_key(void);

int io_left_key(void);

int io_right_key(void);

int io_space_key(void);

int io_a_key(void);

int io_z_key(void);

int io_x_key(void);

int io_c_key(void);

int io_r_key(void);

int io_v_key(void);

bool io_end(void);
