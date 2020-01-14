#pragma once

#include <stdlib.h>
#include <stdio.h>

struct Player
{
    int color;
    char* array;
    int count;
    bool isHuman
};

struct Player List_Init()
{
    struct Player list;
    list.color = 0xff0000ff;
    list.array = malloc(list.count);
    list.count = 21;
    list.isHuman = true;
    return list;
}

void List_Populate(struct Player* self)
{
    for(int i = 0; i < self->count; i++)
        self->array[i] = i;
}

int List_Contains_Int(struct Player* self, int k)
{ 
    for(int i = 0; i < self->count; i++)
    {
        if(self->array[i] == k)
            return 1;
    }
    return 0;
}

void List_Remove_Int(struct Player* self, int k)
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

void List_Print_Array(struct Player* self)
{
    printf("list->array:\n");
    for(int i = 0; i < self->count; i++)
        printf("  >> %d\n", self->array[i]);
}

void List_Print_Count(struct Player* self)
{
    printf("  >>%d pieces left\n", self->count);
}

void List_Destroy(struct Player* self)
{
    free(self->array);  // same as list.array but use -> for pointer
    self->array = NULL;
}
