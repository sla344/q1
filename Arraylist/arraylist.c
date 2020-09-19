
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "arraylist.h"

////////////////////////////////////////////////////////////////////////////////
//Functions that you need to implement:

/*
 * Append the value x to the end of the arraylist. If necessary, double the
 * capacity of the arraylist.
 */
void arraylist_add(arraylist *a, void *x)
{
    //printf("len: %u \n size: %u \n", a->length, a->buffer_size);
    arraylist_print(a);

    if(a->length == a->buffer_size){
        a->buffer_size = a->buffer_size * 2;
        a->buffer = realloc(a->buffer, a->buffer_size * sizeof(void*));
    }
    ///printf("len: %u \n size: %u \n", a->length, a->buffer_size);

    a->buffer[a->length++] = x;
        //printf("len: %u \n size: %u \n", a->length, a->buffer_size);

}   

/*
 * Store x at the specified index of the arraylist. Previously stored values
 * should be moved back rather than overwritten. It is undefined behavior to
 * insert an element with an index beyond the end of an arraylist.
 */
void arraylist_insert(arraylist *a, unsigned int index, void *x)
{
    // TODO
    // Hint: Consider how you could implement this function in terms of
    // arraylist_add()
    

    // for(unsigned int i = a->length; i > index; i--){
    //     a->buffer[i] = a->buffer[i-1]; 
    // }


    // a->buffer[index] = x;
    // a->length++;


    //arraylist_print(a);
    arraylist_add(a, NULL);
    //void *dest = a->buffer + (index+1)*sizeof(void *);
    //void *src = a->buffer + index*sizeof(void *);
    void *dest = a->buffer[index+1];
    void *src = a->buffer[index];
    size_t len = (a->length-index-1) * sizeof(void *);

    
    memmove(dest, src, len);
    //arraylist_print(a);
    src = x;
    //arraylist_print(a);



   
}

/*
 * Free any memory used by that arraylist.
 */
void arraylist_free(arraylist *a)
{
    // Hint: How many times is malloc called when creating a new arraylist?
    //malloc for a->buffer and a
    free(a->buffer); 
    free(a);
}

////////////////////////////////////////////////////////////////////////////////

arraylist *arraylist_new()
{
    arraylist *a = (arraylist *)malloc(sizeof(arraylist));
    a->buffer = (void **)malloc(4 * sizeof(void *));
    a->buffer_size = 4;
    a->length = 0;

    return a;
}

void arraylist_remove(arraylist *a, unsigned int index)
{
    for (unsigned int i = index; i < a->length - 1; i++)
        a->buffer[i] = a->buffer[i + 1];

    --a->length;
}

void *arraylist_get(arraylist *a, unsigned int index)
{
    return a->buffer[index];
}

void arraylist_print(arraylist *a)
{
    printf("[");
    if (a->length > 0)
    {
        for (unsigned int i = 0; i < a->length - 1; i++)
            printf("%d, ", *(int *)arraylist_get(a, i));
        printf("%d", *(int *)arraylist_get(a, a->length - 1));
    }

    printf("]\n");
}

void arraylist_output(arraylist *a, char *output, int *pos)
{
    int index = 0;
    sprintf(output + *pos, "[");
    ++*pos;
    if (a->length > 0)
    {
        for (unsigned int i = 0; i < a->length - 1; i++)
        {
            index = sprintf(output + *pos, "%d, ", *(int *)arraylist_get(a, i));
            (*pos) = (*pos) + index;
        }
        index = sprintf(output + *pos, "%d", *(int *)arraylist_get(a, a->length - 1));
        (*pos) = (*pos) + index;
    }
    sprintf(output + *pos, "]\n");
    (*pos) = (*pos) + 2;
}
