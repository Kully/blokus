#pragma once

#include <stdlib.h>
#include <stdio.h>

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

struct List arr_list[4];  // holds structs for Players 1,2,3,4

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
