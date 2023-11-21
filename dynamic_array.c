#include <stdio.h>
#include <stdlib.h>

const int ARRAY_SIZE = 2;

struct dynamic_array
{
    int *array;
    int length;
    int size;
};

void init_array(struct dynamic_array *da, int initial_size)
{
    da->array = malloc(sizeof(int) * initial_size);
    da->size = initial_size;
    da->length = 0;
}

void add(struct dynamic_array *da, int elem)
{
    printf("Adding an element. Current array size: %lu\n", sizeof(da->array));
    if (da->length == da->size)
    {
        printf("resizing the array");
        da->size *= 2;
        // realloc will
        // deallocate old memory, and
        // allocate new size memory and
        // copy the contents from the old ones as much as it can in the new memory
        da->array = realloc(da->array, sizeof(int) * da->size);
    }
    da->array[da->length++] = elem;
}

void display(struct dynamic_array *da)
{
    printf("Size: %d", da->size);
    printf("Length: %d", da->length);
    for (int i = 0; i < da->length; i++)
    {
        printf("\n%d: %d", i, da->array[i]);
    }
}

int main()
{
    struct dynamic_array da;

    init_array(&da, 3);

    add(&da, 10);
    add(&da, 21);
    add(&da, 13);
    add(&da, 11);
    add(&da, 19);
    add(&da, 44);

    display(&da);

    return 0;
}
