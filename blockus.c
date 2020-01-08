#include "lib.h"
#include "stdio.h"
#include "stdlib.h"


int piece17[3][3] = {
    {1, 0, 0},
    {1, 0, 0},
    {1, 1, 1},
};
int piece18[3][3] = {
    {1, 1, 0},
    {0, 1, 1},
    {0, 0, 1},
};
int piece19[3][3] = {
    {1, 0, 0},
    {1, 1, 1},
    {0, 0, 1},
};
int piece20[3][3] = {
    {1, 0, 0},
    {1, 1, 1},
    {0, 1, 0},
};
int piece21[3][3] = {
    {0, 1, 0},
    {1, 1, 1},
    {0, 1, 0},
};


int blue()
{
    return 0XFF0000FF;  // PLAYER 1
}
int yellow()
{
    return 0XFFFFFF00;  // PLAYER 2
}
int red()
{
    return 0XFFFF0000;  // PLAYER 3
}
int green()
{
    return 0XFF00FF00;  // PLAYER 4
}

int piece_overlaps_3r3c(int x, int y, int array[3][3])
{
    for(int r=0;r< 3;r++)
    for(int c=0;c< 3;c++)
        if(array[r][c] == 1 && get(x,y) != 0x0)
        {
            return 1;
        }
    return 0;
}

int piece_out_of_bounds_3r3c(int x, int y, int array[3][3])
{
    for(int r=0;r< 3;r++)
    for(int c=0;c< 3;c++)
        if(array[r][c] == 1 && ((x+c)>=20 || (y+r)>=20))
        {
            return 1;
        }
    return 0;
}

void place_piece_3r3c(int x, int y, int array[3][3], int color)
{
    for(int r=0;r< 3;r++)
    for(int c=0;c< 3;c++)
        if(array[r][c] == 1)
        {
            put(x+c, y+r, color);
        }
}

void place_piece_3r3c_if_ok(int x, int y, int array[3][3], int color)
{
    if(!piece_overlaps_3r3c(x,y,array) && !piece_out_of_bounds_3r3c(x,y,array))
    {
        place_piece_3r3c(x, y, array, color);
    }
}

void verticalReflection()
{

}

void horizontalReflection()
{

}

// find online
void rotate_piece_90_cw()
{

}
void rotate_piece_90_ccw()
{

}



int main(void)
{
    setup();
    resize(20);
    while(!end())
    {
        lock();
        clear();  // CODE BEGINS HERE

        place_piece_3r3c_if_ok(14, 15, piece19, yellow());

        unlock();  // CODE ENDS HERE
        delay(15);
    }
    shutdown();
}
