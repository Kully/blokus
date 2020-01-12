#include "lib.h"
#include "stdio.h"
#include "stdlib.h"



int blue()   {return 0xff0000ff;}   // PLAYER 1
int yellow() {return 0xffffff00;}   // PLAYER 2
int red()    {return 0xffff0000;}   // PLAYER 3
int green()  {return 0xff00ff00;}   // PLAYER 4

int pieceLookup[][4][5][5] = {
    // PIECE 1
    {
        {
            {1}
        },
    },
    // PIECE 2
    {
        {
            {1},
            {1}
        },
        {
            {1, 1},
        },
    },
    // PIECE 3
    {
        {
            {1},
            {1},
            {1}
        },
        {
            {1, 1, 1},
        },
    },
    // PIECE 4
    {
        {
            {1, 0},
            {1, 1}
        },
        {
            {1, 1},
            {1, 0}
        },
        {
            {1, 1},
            {0, 1}
        },
        {
            {0, 1},
            {1, 1}
        },
    },
    // PIECE 5
    {
        {
            {1},
            {1},
            {1},
            {1},
        },
        {
            {1, 1, 1, 1}
        }
    },
    // PIECE 6
    {
        {
            {0, 1},
            {0, 1},
            {1, 1},
        },
        {
            {1, 0, 0},
            {1, 1, 1},
        },
        {
            {1, 1},
            {1, 0},
            {1, 0},
        },
        {
            {1, 1, 1},
            {0, 0, 1},
        },
    },
    // PIECE 7
    {
        {
            {1, 0},
            {1, 1},
            {1, 0},
        },
        {
            {1, 1, 1},
            {0, 1, 0},
        },
        {
            {0, 1},
            {1, 1},
            {0, 1},
        },
        {
            {0, 1, 0},
            {1, 1, 1},
        },
    },
    // PIECE 8
    {
        {
            {1, 1},
            {1, 1},
        },
    },
    // PIECE 9
    {
        {
            {1, 1, 0},
            {0, 1, 1},
        },
        {
            {0, 1},
            {1, 1},
            {1, 0}
        },
    },
    // PIECE 10
    {
        {
            {1},
            {1},
            {1},
            {1},
            {1},
        },
        {
            {1, 1, 1, 1, 1},
        },
    },
    // PIECE 11
    {
        {
            {0, 1},
            {0, 1},
            {0, 1},
            {1, 1},
        },
        {
            {1, 0, 0, 0},
            {1, 1, 1, 1},
        },
        {
            {1, 1},
            {1, 0},
            {1, 0},
            {1, 0},
        },
        {
            {1, 1, 1, 1},
            {0, 0, 0, 1},
        },
    },
    // PIECE 12
    {
        {
            {0, 1},
            {0, 1},
            {1, 1},
            {1, 0},
        },
        {
            {1, 1, 0, 0},
            {0, 1, 1, 1},
        },
        {
            {0, 1},
            {1, 1},
            {1, 0},
            {1, 0},
        },
        {
            {1, 1, 1, 0},
            {0, 0, 1, 1},
        },
    },
    // PIECE 13
    {
        {
            {0, 1},
            {1, 1},
            {1, 1},
        },
        {
            {1, 1, 0},
            {1, 1, 1},
        },
        {
            {1, 1},
            {1, 1},
            {1, 0},
        },
        {
            {1, 1, 1},
            {0, 1, 1},
        },
    },
    // PIECE 14
    {
        {
            {1, 1},
            {0, 1},
            {1, 1},
        },
        {
            {1, 0, 1},
            {1, 1, 1}
        },
        {
            {1, 1},
            {1, 0},
            {1, 1},
        },
        {
            {1, 1, 1},
            {1, 0, 1}
        },
    },
    // PIECE 15
    {
        {
            {1, 0},
            {1, 1},
            {1, 0},
            {1, 0},
        },
        {
            {1, 1, 1, 1},
            {0, 0, 1, 0},
        },
        {
            {0, 1},
            {0, 1},
            {1, 1},
            {0, 1},
        },
        {
            {0, 1, 0, 0},
            {1, 1, 1, 1},
        },
    },
    // PIECE 16
    {
        {
            {0, 1, 0},
            {0, 1, 0},
            {1, 1, 1},
        },
        {
            {1, 0, 0},
            {1, 1, 1},
            {1, 0, 0},
        },
        {
            {1, 1, 1},
            {0, 1, 0},
            {0, 1, 0},
        },
        {
            {0, 0, 1},
            {1, 1, 1},
            {0, 0, 1},
        },
    },
    // PIECE 17
    {
        {
            {1, 0, 0},
            {1, 0, 0},
            {1, 1, 1},
        },
        {
            {1, 1, 1},
            {1, 0, 0},
            {1, 0, 0},
        },
        {
            {1, 1, 1},
            {0, 0, 1},
            {0, 0, 1},
        },
        {
            {0, 0, 1},
            {0, 0, 1},
            {1, 1, 1},
        }
    },
    // PIECE 18
    {
        {
            {1, 1, 0},
            {0, 1, 1},
            {0, 0, 1},
        },
        {
            {0, 0, 1},
            {0, 1, 1},
            {1, 1, 0},
        },
        {
            {1, 0, 0},
            {1, 1, 0},
            {0, 1, 1},
        },
        {
            {0, 1, 1},
            {1, 1, 0},
            {1, 0, 0},
        },
    },
    // PIECE 19
    {
        {
            {1, 0, 0},
            {1, 1, 1},
            {0, 0, 1},
        },
        {
            {0, 1, 1},
            {0, 1, 0},
            {1, 1, 0},
        },
    },
    // PIECE 20
    {
        {
            {1, 0, 0},
            {1, 1, 1},
            {0, 1, 0},
        },
        {
            {0, 1, 1},
            {1, 1, 0},
            {0, 1, 0},
        },
        {
            {0, 1, 0},
            {1, 1, 1},
            {0, 0, 1},
        },
        {
            {0, 1, 0},
            {0, 1, 1},
            {1, 1, 0},
        },
    },
    // PIECE 21
    {
        {
            {0, 1, 0},
            {1, 1, 1},
            {0, 1, 0},
        },
    }
};

// max_rotations, height, width
int pieceStats[21][3] = {
    {1, 1, 1},  // 1
    {2, 2, 1},  // 2
    {2, 3, 1},  // 3
    {4, 2, 2},  // 4
    {2, 4, 1},  // 5
    {4, 3, 2},  // 6
    {4, 3, 2},  // 7
    {1, 2, 2},  // 8
    {2, 2, 3},  // 9
    {2, 5, 1},  // 10
    {4, 4, 2},  // 11
    {4, 4, 2},  // 12
    {4, 3, 2},  // 13
    {4, 3, 2},  // 14
    {4, 4, 2},  // 15
    {4, 3, 3},  // 16
    {4, 3, 3},  // 17
    {4, 3, 3},  // 18
    {2, 3, 3},  // 19
    {4, 3, 3},  // 20
    {1, 3, 3},  // 21
};

// holds all the colors
int currentBoard[20][20] = {0};

void move_currentBoard_to_vram(int array[20][20])
{
    for(int i=0;i<20;i++)
    for(int j=0;j<20;j++)
        {
            put(i, j, array[j][i]);
        }
}

void place_piece_to_CurrentBoard(int x, int y, int color, int array[5][5])
{
    for(int r=0;r<5;r++)
    for(int c=0;c<5;c++)
        if(array[r][c] == 1)
        {
            currentBoard[y+r][x+c] = color;
        }
}

int piece_can_be_placed(int x, int y, int color, int array[5][5])
{
    for(int r=0;r<5;r++)
    for(int c=0;c<5;c++)
        if(array[c][r] == 1)
        {
            // piece overlapping
            if(currentBoard[y+c][x+r] != 0)
            {
                return 0;
            }
            // only corners touching of same color
            if(currentBoard[y+c + 1][x+r] == color)
            {
            	return 0;
            }
            if(currentBoard[y+c - 1][x+r] == color)
            {
            	return 0;
            }
            if(currentBoard[y+c][x+r + 1] == color)
            {
            	return 0;
            }
            if(currentBoard[y+c][x+r - 1] == color)
            {
            	return 0;
            }
        }
    return 1;
}

void draw_piece(int x, int y, int color, int array[5][5])
{
    for(int r=0;r<5;r++)
    for(int c=0;c<5;c++)
        if(array[r][c] == 1)
        {
            put(x+c, y+r, color);
        }
}

void remove_int_from_array(int integer, int array[], int array_size)
{
    printf("remove_int_from_array(...)\n");

    for(int idx=0; idx<array_size; idx++)
    {
        if(array[idx]==integer)
        {
            array[idx] = -1;
        }
    }
}

int main(void)
{
    // player input
    int RIGHT_KEY_COUNTER = 0;
    int LEFT_KEY_COUNTER = 0;
    int UP_KEY_COUNTER = 0;
    int DOWN_KEY_COUNTER = 0;
    int Z_KEY_COUNTER = 0;
    int X_KEY_COUNTER = 0;
    int C_KEY_COUNTER = 0;

    int pieceLookup_len = 21;  // number of pieces

    // active piece variables
    int height, width, max_rot, dummy;
    int active_x = 0;
    int active_y = 0;
    int rot = 0;       // init rotation
    int piece_idx = 0;

    
    int c_idx = 0;
    int colors[4] = {blue(), yellow(), red(), green()};

    // pointers to pieces
    int Player_1234_Pieces_Left[4][21] = {
        {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20},
        {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20},
        {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20},
        {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20},
    };

    int P1_size = 21;
    int P2_size = 21;
    int P3_size = 21;
    int P4_size = 21;

    max_rot = pieceStats[piece_idx][0];
    height = pieceStats[piece_idx][1];
    width = pieceStats[piece_idx][2];

    setup();
    resize(20);
    while(!end())
    {
        lock();
        clear();

        // move up
        if(UP_KEY())
        {
            UP_KEY_COUNTER += 1;
            if(UP_KEY_COUNTER == 1){
                active_y -= 1;
            }
        } else UP_KEY_COUNTER = 0;

        // move down
        if(DOWN_KEY())
        {            
            DOWN_KEY_COUNTER += 1;
            if(DOWN_KEY_COUNTER == 1){
                active_y += 1;
            }
        } else DOWN_KEY_COUNTER = 0;

        // move down
        if(LEFT_KEY())
        {
            LEFT_KEY_COUNTER += 1;
            if(LEFT_KEY_COUNTER == 1){
                active_x -= 1;
            }
        } else LEFT_KEY_COUNTER = 0;

        // move right
        if(RIGHT_KEY())
        {
            RIGHT_KEY_COUNTER += 1;
            if(RIGHT_KEY_COUNTER == 1){
                active_x += 1;
            }
        } else RIGHT_KEY_COUNTER = 0;


        // rotate piece
        if(Z_KEY())
        {
            Z_KEY_COUNTER += 1;
            if(Z_KEY_COUNTER == 1){
                rot += 1;
                if(rot >= max_rot) rot = 0;

                // swap height and width
               	dummy = width;
               	width = height;
               	height = dummy;
            }
        } else Z_KEY_COUNTER = 0;

        // swap piece
        if(X_KEY())
        {
            X_KEY_COUNTER += 1;
            if(X_KEY_COUNTER == 1){
                piece_idx += 1;
                if(piece_idx >= pieceLookup_len)
                {
                    piece_idx = 0;
                }
                rot = 0;  // init rotation upon swapping piece

                // reset variables
                max_rot = pieceStats[piece_idx][0];
                height = pieceStats[piece_idx][1];
                width = pieceStats[piece_idx][2];
            }
        } else X_KEY_COUNTER = 0;

        // change color
        if(C_KEY())
        {
            C_KEY_COUNTER += 1;
            if(C_KEY_COUNTER == 1){
                c_idx += 1;
                if(c_idx >= 4) c_idx = 0;
            }
        } else C_KEY_COUNTER = 0;


        // keep pieces on screen
        if(active_x + width > 20) active_x -= 1;
        if(active_x < 0) active_x += 1;

        if(active_y + height > 20) active_y -= 1;
        if(active_y < 0) active_y += 1;

        // place piece
        if(SPACE_KEY())
        {
            if(piece_can_be_placed(active_x, active_y, colors[c_idx],
                                   pieceLookup[piece_idx][rot]))
            {
                place_piece_to_CurrentBoard(
                    active_x,
                    active_y,
                    colors[c_idx],
                    pieceLookup[piece_idx][rot]
                );

                // advance color
                c_idx += 1;
                if(c_idx >= 4) c_idx = 0;

                // printf("\npiece_idx %i\n", piece_idx);
                // remove_int_from_array(piece_idx, Player_1234_Pieces_Left[0]);
                piece_idx = 0;

                // reset variables
                max_rot = pieceStats[piece_idx][0];
                height = pieceStats[piece_idx][1];
                width = pieceStats[piece_idx][2];

            }
        }

        // reset board
        if(R_KEY())
        {
            for(int i=0; i<20; i++)
            for(int j=0; j<20; j++)
                currentBoard[i][j] = 0x0;
        }

        // draw current board
        move_currentBoard_to_vram(currentBoard);

        // draw active piece
        draw_piece(
            active_x,
            active_y,
            colors[c_idx],
            pieceLookup[piece_idx][rot]
        );

        unlock();
        delay(15);
    }
    shutdown();
}
