#include "io.h"
#include "Player.h"
#include "Pieces.h"

#include "stdio.h"
#include "stdlib.h"

#define BOARD_SIZE 20


struct Player arr_list[4];                       // holds structs for Players 1,2,3,4
int currentBoard[BOARD_SIZE][BOARD_SIZE] = {0};  // placed pixels in 2d array

void Init_Players(struct Player arr_list[4])
{
    arr_list[0] =  Player_Init();    // PLAYER 1
    arr_list[0].color = 0xff0000ff;  // blue
    Player_Populate(&arr_list[0]);

    arr_list[1] =  Player_Init();    // PLAYER 2
    arr_list[1].color = 0xffffff00;  // yellow
    Player_Populate(&arr_list[1]);

    arr_list[2] =  Player_Init();    // PLAYER 3
    arr_list[2].color = 0xffff0000;  // red
    Player_Populate(&arr_list[2]);

    arr_list[3] =  Player_Init();    // PLAYER 4
    arr_list[3].color = 0xff00ff00;  // green
    Player_Populate(&arr_list[3]);
}

void CurrentBoard_To_Vram(int array[BOARD_SIZE][BOARD_SIZE])
{
    for(int i = 0; i<BOARD_SIZE; i++)
    for(int j = 0; j<BOARD_SIZE; j++)
        io_put(i, j, array[j][i]);
}

void Write_Piece_To_CurrentBoard(int x, int y, int color, int array[5][5])
{
    for(int r=0; r<5; r++)
    for(int c=0; c<5; c++)
        if(array[r][c] == 1)
            currentBoard[y+r][x+c] = color;
}

bool Piece_Covers_Corner_Square(int x, int y, int array[5][5])
{
    bool coversCornerSquare = false;
    for(int r=0;r<5;r++)
    for(int c=0;c<5;c++)
        if(array[c][r] == 1)
        {
            if(y+c == 0 && x+r == 0)
                coversCornerSquare = true;
            if(y+c == BOARD_SIZE-1 && x+r == 0)
                coversCornerSquare = true;
            if(y+c == 0 && x+r == BOARD_SIZE-1)
                coversCornerSquare = true;
            if(y+c == BOARD_SIZE-1 && x+r == BOARD_SIZE-1)
                coversCornerSquare = true;
        }
    return coversCornerSquare;
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
    if(list.count == 21)
    {
        if(Piece_Covers_Corner_Square(x, y, array))
            return 1;
    }
    else if(touchingCornerSameColor)
        return 1;
    return 0;
}

void Print_Array(int array[5][5])
{
    for(int r=0;r<5;r++)
    {
        printf("\n");
        for(int c=0;c<5;c++)
        {
            if(array[r][c] == 1)
                printf("[X]");
            else
                printf("[ ]");
        }
    }
    printf("\n");
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

void Copy_Piece_to_Preview_Slots(int array[5][5], int Piece_Preview[5][5])
{
    // array := the active piece
    // Piece_Preview := a copy of active piece w/ flipped

    for(int r=0;r<5;r++)
    for(int c=0;c<5;c++)
        if(array[r][c] == 1)
            Piece_Preview[r][c] = 1;
        else
            Piece_Preview[r][c] = 0;
}

void Swap_Rows(int grid[5][5], int row_a, int row_b)
{
    int dummy_row[5] = {0,0,0,0,0};

    for(int i=0;i<5;i++)
    {
        dummy_row[i] = grid[row_a][i];
        grid[row_a][i] = grid[row_b][i];
        grid[row_b][i] = dummy_row[i];
    }
}

int Row_Is_Zero(int row[5])
{
    for(int i=0;i<5;i++)
    {
        if(row[i] != 0)
            return 0;
    }
    return 1;
}

void Flip_Preview_Piece(int grid[5][5])
{
    // reverse the rows
    Swap_Rows(grid, 0, 4);
    Swap_Rows(grid, 1, 3);

    for(int row = 0; row < 5; row++)
    {
        if(Row_Is_Zero(grid[0]))
        {
            // move top row down
            Swap_Rows(grid, 0, 1);
            Swap_Rows(grid, 1, 2);
            Swap_Rows(grid, 2, 3);
            Swap_Rows(grid, 3, 4);          
        }
    }
}

int Count_Unit_Squares_in_Piece(int array[5][5])
{
    int count = 0;
    
    for(int r=0; r<5; r++)
    for(int c=0; c<5; c++)
        if(array[r][c] == 1)
            count++;
    
    return count;
}

void Advance_Player(int* player)
{
    *player += 1;
    if(*player >= 4) *player = 0;
}

void Set_Piece_Stats(int player, int list_idx, int* max_rot, int* height, int* width)
{
    *max_rot = Piece_Info[arr_list[player].array[list_idx]][0];
    *height = Piece_Info[arr_list[player].array[list_idx]][1];
    *width = Piece_Info[arr_list[player].array[list_idx]][2];
}

int main(void)
{
    // ensure keys don't repeat
    int RIGHT_KEY_COUNTER = 0;
    int LEFT_KEY_COUNTER = 0;
    int UP_KEY_COUNTER = 0;
    int DOWN_KEY_COUNTER = 0;
    int A_KEY_COUNTER = 0;
    int S_KEY_COUNTER = 0;
    int E_KEY_COUNTER = 0;
    int P_KEY_COUNTER = 0;
    int Z_KEY_COUNTER = 0;
    int X_KEY_COUNTER = 0;
    int C_KEY_COUNTER = 0;
    int V_KEY_COUNTER = 0;
    int SPACE_KEY_COUNTER = 0;

    // active piece variables
    int max_rot, height, width, dummy;
    int active_x = 0;                     // x of active piece 
    int active_y = 0;                     // y of active piece 
    int rot = 0;                          // init rotation
    int player = 0;                       // keeps track of player
    int list_idx = 0;                     // points to player's pieces
    bool piece_is_ver_reflected = false;  // piece flipped

    int Piece_Preview[5][5] = {
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
    };

    Init_Players(arr_list);
    Set_Piece_Stats(player, list_idx, &max_rot, &height, &width);

    io_setup();
    io_resize(20);
    while(!io_end())
    {
        io_lock();
        io_clear();

        // SKIP PLAYER IF NO MOVES
        if(arr_list[player].count == 0)
            Advance_Player(&player);

        // MOVE PIECE UP
        if(io_up_key())
        {
            UP_KEY_COUNTER += 1;
            if(UP_KEY_COUNTER == 1)
                active_y -= 1;

        } else UP_KEY_COUNTER = 0;

        // MOVE PIECE DOWN
        if(io_down_key())
        {            
            DOWN_KEY_COUNTER += 1;
            if(DOWN_KEY_COUNTER == 1)
                active_y += 1;

        } else DOWN_KEY_COUNTER = 0;

        // MOVE PIECE LEFT
        if(io_left_key())
        {
            LEFT_KEY_COUNTER += 1;
            if(LEFT_KEY_COUNTER == 1)
                active_x -= 1;

        } else LEFT_KEY_COUNTER = 0;

        // MOVE PIECE RIGHT
        if(io_right_key())
        {
            RIGHT_KEY_COUNTER += 1;
            if(RIGHT_KEY_COUNTER == 1)
                active_x += 1;

        } else RIGHT_KEY_COUNTER = 0;

        // SKIP TURN
        if(io_s_key())
        {
            S_KEY_COUNTER += 1;
            if(S_KEY_COUNTER == 1)
                Advance_Player(&player);

        } else S_KEY_COUNTER = 0;

        // ROTATE PIECE
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

        // FLIP PIECE HORIZONTALLY
        if(io_a_key())
        {
            A_KEY_COUNTER += 1;
            if(A_KEY_COUNTER == 1)
                piece_is_ver_reflected = !piece_is_ver_reflected;

        } else A_KEY_COUNTER = 0;

        // PRINT CURRENT PIECE
        if(io_p_key())
        {
            P_KEY_COUNTER += 1;
            if(P_KEY_COUNTER == 1)
                Print_Array(Pieces[arr_list[player].array[list_idx]][rot]);

        } else P_KEY_COUNTER = 0;

        // SWAP PIECE (BACKWARDS)
        if(io_z_key())
        {
            Z_KEY_COUNTER += 1;
            if(Z_KEY_COUNTER == 1)
            {
                list_idx -= 1;
                if(list_idx < 0)
                    list_idx = arr_list[player].count - 1;
                rot = 0;  // init rotation of piece

                Set_Piece_Stats(player, list_idx, &max_rot, &height, &width);
            }
        } else Z_KEY_COUNTER = 0;

        // SWAP PIECE (FORWARDS)
        if(io_x_key())
        {
            X_KEY_COUNTER += 1;
            if(X_KEY_COUNTER == 1)
            {
                list_idx += 1;
                if(list_idx >= arr_list[player].count)
                    list_idx = 0;
                rot = 0;  // init rotation of piece

                Set_Piece_Stats(player, list_idx, &max_rot, &height, &width);
            }
        } else X_KEY_COUNTER = 0;

        // keep pieces on screen
        if(active_x + width > BOARD_SIZE) active_x -= 1;
        if(active_x < 0) active_x += 1;
        if(active_y + height > BOARD_SIZE) active_y -= 1;
        if(active_y < 0) active_y += 1;

        // PLACE PIECE DOWN
        if(io_space_key())
        {
            SPACE_KEY_COUNTER += 1;
            if(SPACE_KEY_COUNTER == 1)
            {
                if(Can_Place_Piece(active_x, active_y, arr_list[player], Piece_Preview))
                {
                    Write_Piece_To_CurrentBoard(
                        active_x,
                        active_y,
                        arr_list[player].color,
                        Piece_Preview
                    );

                    // record last piece played
                    arr_list[player].lastPiecePlayed = arr_list[player].array[list_idx];

                    Player_Remove_Int(
                        &arr_list[player],
                        arr_list[player].array[list_idx]
                    );

                    printf("Player %d Made a Move\n", player+1);
                    Player_Print_Count(&arr_list[player]);
                    
                    list_idx = 0;
                    rot = 0;

                    Advance_Player(&player);
                    Set_Piece_Stats(player, list_idx, &max_rot, &height, &width);
                    
                    // set pieces to middle of board
                    active_x = 9;
                    active_y = 9;
                }
            }
        } else SPACE_KEY_COUNTER = 0;

        // END GAME AND ADD SCORES UP
        if(io_e_key())
        {
            E_KEY_COUNTER += 1;
            if(E_KEY_COUNTER == 1)
            {
                int winner = 0;
                int maxVal = -100;

                // calculate scores
                for(int p=0; p<4; p++)
                {
                    // +15 if all pieces placed
                    if(arr_list[p].count == 0)
                        arr_list[p].score += 15;

                    // +5 if last piece placed was smallest piece
                    if(arr_list[p].lastPiecePlayed == 0)
                        arr_list[p].score += 5;

                    // subtract all unit squares of remaining pieces
                    for(int i=0; i<arr_list[p].count; i++)
                    {
                        int count = Count_Unit_Squares_in_Piece(
                            Pieces[arr_list[p].array[i]][0]
                        );
                        arr_list[p].score -= count;
                    }

                    if(arr_list[p].score > maxVal)
                    {
                        maxVal = arr_list[p].score;
                        winner = p;
                    }

                }
                printf("\nSCORES:\n");
                printf("  PLAYER 1: %d \n", arr_list[0].score);
                printf("  PLAYER 2: %d \n", arr_list[1].score);
                printf("  PLAYER 3: %d \n", arr_list[2].score);
                printf("  PLAYER 4: %d \n", arr_list[3].score);

                printf("PLAYER %d WINS! \n", winner+1);
                exit(1);
            }
        } else E_KEY_COUNTER = 0;

        // draw current board
        CurrentBoard_To_Vram(currentBoard);

        Copy_Piece_to_Preview_Slots(Pieces[arr_list[player].array[list_idx]][rot],
                                    Piece_Preview);
        if(piece_is_ver_reflected)
            Flip_Preview_Piece(Piece_Preview);

        // draw active piece
        Draw_Piece(
            active_x,
            active_y,
            arr_list[player].color,
            Piece_Preview
        );

        io_unlock();
        io_delay(15);
    }
    io_shutdown();
}
