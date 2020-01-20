#include "io.h"
#include "Player.h"
#include "Pieces.h"

#include "stdio.h"
#include "stdlib.h"

#define DEBUG 1


struct Player arr_list[4];  // holds structs for Players 1,2,3,4

int currentBoard[20][20] = {0};  // placed pixels in 2d array

void CurrentBoard_To_Vram(int array[20][20])
{
    for(int i = 0; i<20; i++)
    for(int j = 0; j<20; j++)
        io_put(i, j, array[j][i]);
}

void Write_Piece_To_CurrentBoard(int x, int y, int color, int array[5][5])
{
    for(int r=0; r<5; r++)
    for(int c=0; c<5; c++)
        if(array[r][c] == 1)
            currentBoard[y+r][x+c] = color;
}

bool Piece_Covers_Corner_Square(int x, int y, struct Player list, int array[5][5])
{
    bool onePieceCoversCorner = false;
    for(int r=0;r<5;r++)
    for(int c=0;c<5;c++)
        if(array[c][r] == 1)
        {
            if(y+c == 0 && x+r == 0)
                onePieceCoversCorner = true;
            if(y+c == 19 && x+r == 0)
                onePieceCoversCorner = true;
            if(y+c == 0 && x+r == 19)
                onePieceCoversCorner = true;
            if(y+c == 19 && x+r == 19)
                onePieceCoversCorner = true;
        }

    return onePieceCoversCorner;
}

int Can_Place_Piece(int x, int y, struct Player list, int array[5][5])
{
    bool touchingCornerSameColor = false;
    for(int r=0;r<5;r++)
    for(int c=0;c<5;c++)
        if(array[c][r] == 1)
        {
            // piece overlapping
            if(currentBoard[y+c][x+r] != 0)
                return 0;

            // not touching edges
            if(currentBoard[y+c + 1][x+r] == list.color)
            	return 0;
            if(currentBoard[y+c - 1][x+r] == list.color)
            	return 0;
            if(currentBoard[y+c][x+r + 1] == list.color)
            	return 0;
            if(currentBoard[y+c][x+r - 1] == list.color)
            	return 0;

            // at least one corner touching - for move > 1
            if(currentBoard[y+c + 1][x+r + 1] == list.color)
                touchingCornerSameColor = true;
            if(currentBoard[y+c - 1][x+r + 1] == list.color)
                touchingCornerSameColor = true;
            if(currentBoard[y+c + 1][x+r - 1] == list.color)
                touchingCornerSameColor = true;
            if(currentBoard[y+c - 1][x+r - 1] == list.color)
                touchingCornerSameColor = true;
        }
    if(list.count == 21 && Piece_Covers_Corner_Square(x, y, list, array))
        return 1;
    else if(touchingCornerSameColor)
        return 1;
    return 0;
}

void Init_Players(struct Player arr_list[4])
{
    // PLAYER 1
    arr_list[0] =  Player_Init();
    arr_list[0].color = 0xffb0eacd;  // blue  0xff0000ff
    arr_list[0].isHuman = true;  // HUMAN
    Player_Populate(&arr_list[0]);

    // PLAYER 2
    arr_list[1] =  Player_Init();
    arr_list[1].color = 0xffffff00;  // yellow
    arr_list[1].isHuman = true;  // HUMAN
    Player_Populate(&arr_list[1]);

    // PLAYER 3
    arr_list[2] =  Player_Init();
    arr_list[2].color = 0xffff0000;  // red
    arr_list[2].isHuman = false;  // BOT
    Player_Populate(&arr_list[2]);

    // PLAYER 4
    arr_list[3] =  Player_Init();
    arr_list[3].color = 0xff00ff00;  // green
    arr_list[3].isHuman = true;  // HUMAN
    Player_Populate(&arr_list[3]);
}

void Flip_Piece_Horizontally(int array[5][5])
{
    // malloc(...)
    // point to new one
}

void Draw_Piece(int x, int y, int color, int array[5][5])
{
    for(int r=0;r<5;r++)
    for(int c=0;c<5;c++)
        if(array[r][c] == 1)
        {
            io_put(x+c, y+r, color);
        }
}

int main(void)
{
    // ensure keys don't repeat
    int RIGHT_KEY_COUNTER = 0;
    int LEFT_KEY_COUNTER = 0;
    int UP_KEY_COUNTER = 0;
    int DOWN_KEY_COUNTER = 0;
    int A_KEY_COUNTER = 0;
    int Z_KEY_COUNTER = 0;
    int X_KEY_COUNTER = 0;
    int C_KEY_COUNTER = 0;
    int V_KEY_COUNTER = 0;
    int SPACE_KEY_COUNTER = 0;

    // active piece variables
    int height, width, max_rot, dummy;
    int active_x = 0;   // x of active piece 
    int active_y = 0;   // y of active piece 
    int rot = 0;        // init rotation
    int list_idx = 0;  // points to array of player's pieces
    int player = 0;     // keeps track of player

    Init_Players(arr_list);
 
    // grab meta data for selected piece
    max_rot = Piece_Info[arr_list[player].array[list_idx]][0];
    height = Piece_Info[arr_list[player].array[list_idx]][1];
    width = Piece_Info[arr_list[player].array[list_idx]][2];

    io_setup();
    io_resize(20);
    while(!io_end())
    {
        io_lock();
        io_clear();

        if(!arr_list[player].isHuman)
        {
            // do ai stuff
        }
        else
        {
            // printf("A HUMAN\n");
        }

        // move up
        if(io_up_key())
        {
            UP_KEY_COUNTER += 1;
            if(UP_KEY_COUNTER == 1)
            {
                active_y -= 1;
            }
        } else UP_KEY_COUNTER = 0;

        // move down
        if(io_down_key())
        {            
            DOWN_KEY_COUNTER += 1;
            if(DOWN_KEY_COUNTER == 1)
            {
                active_y += 1;
            }
        } else DOWN_KEY_COUNTER = 0;

        // move down
        if(io_left_key())
        {
            LEFT_KEY_COUNTER += 1;
            if(LEFT_KEY_COUNTER == 1)
            {
                active_x -= 1;
            }
        } else LEFT_KEY_COUNTER = 0;

        // move right
        if(io_right_key())
        {
            RIGHT_KEY_COUNTER += 1;
            if(RIGHT_KEY_COUNTER == 1)
            {
                active_x += 1;
            }
        } else RIGHT_KEY_COUNTER = 0;

        // rotate piece
        if(io_c_key())
        {
            C_KEY_COUNTER += 1;
            if(C_KEY_COUNTER == 1)
            {
                rot += 1;
                if(rot >= max_rot) rot = 0;

                // swap height and width
               	dummy = width;
               	width = height;
               	height = dummy;
            }
        } else C_KEY_COUNTER = 0;

        // flip horizontally
        // if(io_a_key())
        // {
        //     A_KEY_COUNTER += 1;
        //     if(A_KEY_COUNTER)
        //     {

        //     }
        // } else A_KEY_COUNTER = 0;

        // swap piece (backwards)
        if(io_z_key())
        {
            Z_KEY_COUNTER += 1;
            if(Z_KEY_COUNTER == 1)
            {
                list_idx -= 1;
                if(list_idx < 0)
                    list_idx = arr_list[player].count - 1;
                rot = 0;  // init rotation upon swapping piece

                // reset variables
                max_rot = Piece_Info[arr_list[player].array[list_idx]][0];
                height = Piece_Info[arr_list[player].array[list_idx]][1];
                width = Piece_Info[arr_list[player].array[list_idx]][2];
            }
        } else Z_KEY_COUNTER = 0;

        // swap piece (forwards)
        if(io_x_key())
        {
            X_KEY_COUNTER += 1;
            if(X_KEY_COUNTER == 1)
            {
                list_idx += 1;
                if(list_idx >= arr_list[player].count)
                    list_idx = 0;
                rot = 0;  // init rotation upon swapping piece

                // reset variables
                max_rot = Piece_Info[arr_list[player].array[list_idx]][0];
                height = Piece_Info[arr_list[player].array[list_idx]][1];
                width = Piece_Info[arr_list[player].array[list_idx]][2];
            }
        } else X_KEY_COUNTER = 0;

        // keep pieces on screen
        if(active_x + width > 20) active_x -= 1;
        if(active_x < 0) active_x += 1;

        if(active_y + height > 20) active_y -= 1;
        if(active_y < 0) active_y += 1;

        // place piece down
        if(io_space_key())
        {
            SPACE_KEY_COUNTER += 1;
            if(SPACE_KEY_COUNTER == 1)
            {
                if(Can_Place_Piece(
                    active_x, active_y, arr_list[player],
                    Pieces[arr_list[player].array[list_idx]][rot]
                ))
                {
                    Write_Piece_To_CurrentBoard(
                        active_x,
                        active_y,
                        arr_list[player].color,
                        Pieces[arr_list[player].array[list_idx]][rot]
                    );

                    #if DEBUG == 1
                        printf("Player %d Played\n", player+1);
                        Player_Print_Count(&arr_list[player]);
                    #endif

                    Player_Remove_Int(&arr_list[player], arr_list[player].array[list_idx]);
                    
                    // advance color
                    player += 1;
                    if(player >= 4) player = 0;

                    // reset variables
                    max_rot = Piece_Info[arr_list[player].array[list_idx]][0];
                    height = Piece_Info[arr_list[player].array[list_idx]][1];
                    width = Piece_Info[arr_list[player].array[list_idx]][2];

                }
            }
        } else SPACE_KEY_COUNTER = 0;

        // RESET GAME
        if(io_r_key())
        {
            // clear the board
            for(int i=0; i<20; i++)
            for(int j=0; j<20; j++)
                currentBoard[i][j] = 0x0;

            Init_Players(arr_list);
        }

        // draw current board
        CurrentBoard_To_Vram(currentBoard);

        // draw active piece
        Draw_Piece(
            active_x,
            active_y,
            arr_list[player].color,
            Pieces[arr_list[player].array[list_idx]][rot]
        );

        io_unlock();
        io_delay(15);
    }
    io_shutdown();
}
