#include "lib.h"

int blue()
{
    return 0XFF0000FF;
}
int yellow()
{
    return 0XFFFFFF00;
}
int red()
{
    return 0XFFFF0000;
}
int green()
{
    return 0XFF00FF00;
}


int main(void)
{
    int pieceN[3][3] = {
        {0, 1, 0},
        {1, 1, 1},
        {0, 1, 0},
    };
    printf("%d", pieceN[2][2]);


    setup();
    resize(20);
    while(!end())
    {
        lock();
        clear();

        // CODE GOES HERE
        // **************

        // int array[5] = [red(), red()];

        point(0,0,blue());
        point(1,0,blue());
        point(2,0,blue());
        point(4,4,green());

        // **************

        unlock();
        delay(15);
    }
    shutdown();
}

