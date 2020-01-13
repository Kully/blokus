#include "lib.h"
#include "stdio.h"
#include "stdlib.h"

// global constants
#define DEBUG 1

int blue()   {return 0xff0000ff;}   // PLAYER 1
int yellow() {return 0xffffff00;}   // PLAYER 2
int red()    {return 0xffff0000;}   // PLAYER 3
int green()  {return 0xff00ff00;}   // PLAYER 4

struct List
{
    int color;
    char* array;
    int count;
};

struct List __init__()
{
    struct List list;
    list.color = 0xff0000ff;
    list.count = 21;
    list.array = malloc(list.count);
    return list;
}

struct List arr_list[4];  // holds all player info

void List_Populate(struct List* self)
{
    for(int i = 0; i < self->count; i++)
        self->array[i] = i;
}

int List_Contains_Int(struct List* self, int k)
{ 
    for(int i = 0; i < self->count; i++)
    {
        if(self->array[i] == k)
            return 1;
    }
    return 0;
}

void List_Remove_Int(struct List* self, int k)
{
    for(int i = 0; i < self->count; i++)
    {
        if(self->array[i] > k)
        {
            self->array[i-1] = self->array[i];
        }
    }

    // decrement count
    if(self->count > 0)
        self->count --;

    // realloc
    self->array = realloc(self->array, self->count);
}

void List_Print_Array(struct List* self)
{
    printf("list->array:\n");
    for(int i = 0; i < self->count; i++)
        printf("  >> %d\n", self->array[i]);
}

void List_Print_Count(struct List* self)
{
    printf("  >>%d pieces left\n", self->count);
}

void List_Destroy(struct List* self)
{
    free(self->array);  // same as list.array but use -> for pointer
    self->array = NULL;
}

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
    for(int i = 0; i<20; i++)
    for(int j = 0; j<20; j++)
        put(i, j, array[j][i]);
}

void write_piece_to_CurrentBoard(int x, int y, int color, int array[5][5])
{
    for(int r=0; r<5; r++)
    for(int c=0; c<5; c++)
        if(array[r][c] == 1)
            currentBoard[y+r][x+c] = color;
}

bool Piece_Covers_Corner_Square(int x, int y, struct List list, int array[5][5])
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

int piece_can_be_placed(int x, int y, struct List list, int array[5][5])
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
    {
        return 1;
    }
    else if(touchingCornerSameColor)
        return 1;
    return 0;
}

void Init_Players(struct List arr_list[4])
{
    // PLAYER 1
    arr_list[0] =  __init__();
    arr_list[0].color = blue();
    List_Populate(&arr_list[0]);

    // PLAYER 2
    arr_list[1] =  __init__();
    arr_list[1].color = yellow();
    List_Populate(&arr_list[1]);

    // PLAYER 3
    arr_list[2] =  __init__();
    arr_list[2].color = red();
    List_Populate(&arr_list[2]);

    // PLAYER 4
    arr_list[3] =  __init__();
    arr_list[3].color = green();
    List_Populate(&arr_list[3]);
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

int main(void)
{
    // ensure keys don't repeat
    int RIGHT_KEY_COUNTER = 0;
    int LEFT_KEY_COUNTER = 0;
    int UP_KEY_COUNTER = 0;
    int DOWN_KEY_COUNTER = 0;
    int Z_KEY_COUNTER = 0;
    int X_KEY_COUNTER = 0;
    int C_KEY_COUNTER = 0;
    int SPACE_KEY_COUNTER = 0;

    // active piece variables
    int height, width, max_rot, dummy;
    int active_x = 0;   // x of active piece 
    int active_y = 0;   // y of active piece 
    int rot = 0;        // init rotation
    int piece_idx = 0;  // points to array of player's pieces
    int player = 0;     // keeps track of player

    Init_Players(arr_list);
 
    // grab meta data for selected piece
    max_rot = pieceStats[arr_list[player].array[piece_idx]][0];
    height = pieceStats[arr_list[player].array[piece_idx]][1];
    width = pieceStats[arr_list[player].array[piece_idx]][2];

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

        // swap piece (forwards)
        if(X_KEY())
        {
            X_KEY_COUNTER += 1;
            if(X_KEY_COUNTER == 1){
                
                piece_idx += 1;
                if(piece_idx >= arr_list[player].count)
                {
                    piece_idx = 0;
                }
                rot = 0;  // init rotation upon swapping piece

                // reset variables
                max_rot = pieceStats[arr_list[player].array[piece_idx]][0];
                height = pieceStats[arr_list[player].array[piece_idx]][1];
                width = pieceStats[arr_list[player].array[piece_idx]][2];
            }
        } else X_KEY_COUNTER = 0;

        // swap piece (backwards)
        // if(C_KEY())

        // keep pieces on screen
        if(active_x + width > 20) active_x -= 1;
        if(active_x < 0) active_x += 1;

        if(active_y + height > 20) active_y -= 1;
        if(active_y < 0) active_y += 1;

        // place piece down
        if(SPACE_KEY())
        {
            SPACE_KEY_COUNTER += 1;
            if(SPACE_KEY_COUNTER == 1){
                if(piece_can_be_placed(
                    active_x, active_y, arr_list[player],
                    pieceLookup[arr_list[player].array[piece_idx]][rot]
                ))
                {
                    write_piece_to_CurrentBoard(
                        active_x,
                        active_y,
                        arr_list[player].color,
                        pieceLookup[arr_list[player].array[piece_idx]][rot]
                    );

                    #if DEBUG == 1
                        printf("Player %d Played\n", player+1);
                        List_Print_Count(&arr_list[player]);
                    #endif

                    List_Remove_Int(&arr_list[player], arr_list[player].array[piece_idx]);
                    
                    // advance color
                    player += 1;
                    if(player >= 4) player = 0;

                    // reset variables
                    max_rot = pieceStats[arr_list[player].array[piece_idx]][0];
                    height = pieceStats[arr_list[player].array[piece_idx]][1];
                    width = pieceStats[arr_list[player].array[piece_idx]][2];

                }
            }
        } else SPACE_KEY_COUNTER = 0;

        // RESET GAME
        if(R_KEY())
        {
            // clear the board
            for(int i=0; i<20; i++)
            for(int j=0; j<20; j++)
                currentBoard[i][j] = 0x0;

            Init_Players(arr_list);
        }

        // draw current board
        move_currentBoard_to_vram(currentBoard);

        // draw active piece
        draw_piece(
            active_x,
            active_y,
            arr_list[player].color,
            pieceLookup[arr_list[player].array[piece_idx]][rot]
        );

        unlock();
        delay(15);
    }
    shutdown();
}
