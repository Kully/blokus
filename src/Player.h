#pragma once

#include <stdlib.h>
#include <stdio.h>

struct Player
{
    int count;
    char* array;
    int color;
    int score;
    int lastPiecePlayed;
};

struct Player Player_Init()
{
    struct Player list;
    list.count = 21;
    list.array = malloc(sizeof(list) * list.count);
    list.color = 0xff0000ff;
    list.score = 0;
    list.lastPiecePlayed = -1;  // init at -1
    return list;
}

void Player_Populate(struct Player* self)
{
    for(int i = 0; i < self->count; i++)
        self->array[i] = i;
}

int Player_Contains_Int(struct Player* self, int k)
{ 
    for(int i = 0; i < self->count; i++)
    {
        if(self->array[i] == k)
            return 1;
    }
    return 0;
}

void Player_Remove_Int(struct Player* self, int k)
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

void Player_Print_Array(struct Player* self)
{
    printf("list->array:\n");
    for(int i = 0; i < self->count; i++)
        printf("  >> %d\n", self->array[i]);
}

void Player_Print_Count(struct Player* self)
{
    printf("  >>%d pieces left\n", self->count);
}

void Player_Destroy(struct Player* self)
{
    free(self->array);  // same as list.array but use -> for pointer
    self->array = NULL;
}
