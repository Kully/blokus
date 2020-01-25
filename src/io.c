#include "io.h"

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

void io_setup(void)
{
    srand(time(NULL));
    window = SDL_CreateWindow(
            "blokus",
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

void io_resize(int size)
{
    SDL_SetWindowSize(window, xres * size, yres * size);
    SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
}

void io_lock(void)
{
    void* raw;
    int pitch;
    SDL_LockTexture(texture, NULL, &raw, &pitch);
    pixels = (uint32_t*) raw;
}

void io_unlock(void)
{
    SDL_UnlockTexture(texture);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void io_shutdown(void)
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
}

void io_delay(int ms)
{
    SDL_Delay(ms);
}

int io_up_key(void)
{
    SDL_PumpEvents();
    if(key[SDL_SCANCODE_UP])
        return 1;
    return 0;
}

int io_down_key(void)
{
    SDL_PumpEvents();
    if(key[SDL_SCANCODE_DOWN])
        return 1;
    return 0;
}

int io_left_key(void)
{
    SDL_PumpEvents();
    if(key[SDL_SCANCODE_LEFT])
        return 1;
    return 0;
}

int io_right_key(void)
{
    SDL_PumpEvents();
    if(key[SDL_SCANCODE_RIGHT])
        return 1;
    return 0;
}

int io_a_key(void)
{
    SDL_PumpEvents();
    if(key[SDL_SCANCODE_A])
        return 1;
    return 0;
}

int io_s_key(void)
{
    SDL_PumpEvents();
    if(key[SDL_SCANCODE_S])
        return 1;
    return 0;
}

int io_e_key(void)
{
    SDL_PumpEvents();
    if(key[SDL_SCANCODE_E])
        return 1;
    return 0;
}

int io_p_key(void)
{
    SDL_PumpEvents();
    if(key[SDL_SCANCODE_P])
        return 1;
    return 0;
}

int io_z_key(void)
{
    SDL_PumpEvents();
    if(key[SDL_SCANCODE_Z])
        return 1;
    return 0;
}

int io_x_key(void)
{
    SDL_PumpEvents();
    if(key[SDL_SCANCODE_X])
        return 1;
    return 0;
}

int io_c_key(void)
{
    SDL_PumpEvents();
    if(key[SDL_SCANCODE_C])
        return 1;
    return 0;
}

int io_r_key(void)
{
    SDL_PumpEvents();
    if(key[SDL_SCANCODE_R])
        return 1;
    return 0;
}

int io_v_key(void)
{
    SDL_PumpEvents();
    if(key[SDL_SCANCODE_V])
        return 1;
    return 0;
}

int io_space_key(void)
{
    SDL_PumpEvents();
    if(key[SDL_SCANCODE_SPACE])
        return 1;
    return 0;
}

uint32_t io_get(int x, int y)
{
    return pixels[x + y * xres];
}

void io_put(int x, int y, uint32_t pixel)
{
    pixels[x + y * xres] = pixel;
}

void io_clear(void)
{
    for(int x = 0; x < xres; x++)
    for(int y = 0; y < yres; y++)
        io_put(x, y, 0x0);
}

bool io_end(void)
{
    SDL_PumpEvents();
    bool end_or_esc = key[SDL_SCANCODE_ESCAPE] || key[SDL_SCANCODE_END];
    return end_or_esc;
}
