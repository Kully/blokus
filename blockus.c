#include "lib.h"
#include "stdio.h"

int blue() {return 0XFF0000FF;}
int yellow() {return 0XFFFFFF00;}
int red() {return 0XFFFF0000;}
int green() {return 0XFF00FF00;}


void placePieceOnBoard(int x, int y, int array[])
{
    printf("place piece >> arrayPiece: %i", *array[1][1]);
}

int main(void)
{
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

    placePieceOnBoard(3,2,*piece21);

    setup();
    resize(20);
    while(!end())
    {
        lock();
        clear();

        // ***************
        // CODE GOES BELOW
        // ***************

        point(0,0,blue());
        point(1,0,blue());
        point(2,0,blue());
        point(4,4,green());

        // ***************
        // CODE GOES ABOVE
        // ***************

        unlock();
        delay(15);
    }
    shutdown();
}

