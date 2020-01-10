#include "lib.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <math.h>
#include <time.h>


const int xres = 20;
const int yres = 20;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Texture* texture;

uint32_t* pixels;
const uint8_t* key;

void setup(void)
{
    srand(time(NULL));
    window = SDL_CreateWindow(
            "blockus",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            xres,
            yres,
            SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(
            window,
            -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    texture = SDL_CreateTexture(
            renderer,
            SDL_PIXELFORMAT_ARGB8888,
            SDL_TEXTUREACCESS_STREAMING,
            xres,
            yres);
    key = SDL_GetKeyboardState(NULL);
}

void resize(int size)
{
    SDL_SetWindowSize(window, xres * size, yres * size);
    SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
}

void lock(void)
{
    void* raw;
    int pitch;
    SDL_LockTexture(texture, NULL, &raw, &pitch);
    pixels = (uint32_t*) raw;
}

void unlock(void)
{
    SDL_UnlockTexture(texture);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void shutdown(void)
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
}

void delay(int ms)
{
    SDL_Delay(ms);
}

int UP_KEY(void)
{
    SDL_PumpEvents();
    const uint8_t* key = SDL_GetKeyboardState(NULL);
    if(key[SDL_SCANCODE_UP])
    {
        return 1;
    }
    return 0;
}

int DOWN_KEY(void)
{
    SDL_PumpEvents();
    const uint8_t* key = SDL_GetKeyboardState(NULL);
    if(key[SDL_SCANCODE_DOWN])
    {
        return 1;
    }
    return 0;
}

int LEFT_KEY(void)
{
    SDL_PumpEvents();
    const uint8_t* key = SDL_GetKeyboardState(NULL);
    if(key[SDL_SCANCODE_LEFT])
    {
        return 1;
    }
    return 0;
}

int RIGHT_KEY(void)
{
    SDL_PumpEvents();
    const uint8_t* key = SDL_GetKeyboardState(NULL);
    if(key[SDL_SCANCODE_RIGHT])
    {
        return 1;
    }
    return 0;
}

int Z_KEY(void)
{
    SDL_PumpEvents();
    const uint8_t* key = SDL_GetKeyboardState(NULL);
    if(key[SDL_SCANCODE_Z])
    {
        return 1;
    }
    return 0;
}

int X_KEY(void)
{
    SDL_PumpEvents();
    const uint8_t* key = SDL_GetKeyboardState(NULL);
    if(key[SDL_SCANCODE_X])
    {
        return 1;
    }
    return 0;
}

int C_KEY(void)
{
    SDL_PumpEvents();
    const uint8_t* key = SDL_GetKeyboardState(NULL);
    if(key[SDL_SCANCODE_C])
    {
        return 1;
    }
    return 0;
}

int P_KEY(void)
{
    SDL_PumpEvents();
    const uint8_t* key = SDL_GetKeyboardState(NULL);
    if(key[SDL_SCANCODE_P])
    {
        return 1;
    }
    return 0;
}

int SPACE_KEY(void)
{
    SDL_PumpEvents();
    const uint8_t* key = SDL_GetKeyboardState(NULL);
    if(key[SDL_SCANCODE_SPACE])
    {
        return 1;
    }
    return 0;
}


uint32_t get(int x, int y)
{
    return pixels[x + y * xres];
}

void put(int x, int y, uint32_t pixel)
{
    pixels[x + y * xres] = pixel;
}

void square(int x, int y, int w, int h, uint32_t pixel)
{
    for(int _x = x; _x < x+w; _x++)
    for(int _y = y; _y < y+h; _y++)
        put(_x, _y, pixel);
}

void line(int x0, int y0, int x1, int y1, uint32_t pixel)
{
    int dx =  abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs (y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2; /* error value e_xy */
    for (;;)
    {
        put(x0, y0, pixel);
        if(x0 == x1 && y0 == y1)
            break;
        e2 = 2 * err;
        if(e2 >= dy)
        {
            err += dy;
            x0 += sx;
        }
        if(e2 <= dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void circle(int x0, int y0, int radius, uint32_t pixel)
{
    int f = 1 - radius;
    int ddF_x = 1;
    int ddF_y = -2 * radius;
    int x = 0;
    int y = radius;
    put(x0, y0 + radius, pixel);
    put(x0, y0 - radius, pixel);
    put(x0 + radius, y0, pixel);
    put(x0 - radius, y0, pixel);
    while (x < y)
    {
        if(f >= 0)
        {
            y--;
            ddF_y += 2;
            f += ddF_y;
        }
        x++;
        ddF_x += 2;
        f += ddF_x;
        put(x0 + x, y0 + y, pixel);
        put(x0 - x, y0 + y, pixel);
        put(x0 + x, y0 - y, pixel);
        put(x0 - x, y0 - y, pixel);
        put(x0 + y, y0 + x, pixel);
        put(x0 - y, y0 + x, pixel);
        put(x0 + y, y0 - x, pixel);
        put(x0 - y, y0 - x, pixel);
    }
}

void clear(void)
{
    for(int x = 0; x < xres; x++)
    for(int y = 0; y < yres; y++)
        put(x, y, 0x0);
}

bool end(void)
{
    SDL_PumpEvents();

    bool end_or_esc = key[SDL_SCANCODE_ESCAPE] || key[SDL_SCANCODE_END];
    return end_or_esc;
}
