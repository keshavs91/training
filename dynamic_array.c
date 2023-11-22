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
    printf("Added an element.");
    if (da->length == da->size)
    {
        printf("\nresizing the array");
        int s = da->size;
        // da->size *= 2;
        // realloc will
        // deallocate old memory, and
        // allocate new size memory and
        // copy the contents from the old ones as much as it can in the new memory
        // da->array = realloc(da->array, sizeof(int) * da->size);
        int *temp = malloc(sizeof(int) * s);
        for (int i = 0; i < da->length; i++)
        {
            temp[i] = da->array[i];
        }

        free(da->array);
        da->array = malloc(sizeof(int) * s + 2);
        da->size = s + 2;
        da->length = 0;
        // init_array(&da, da->size*2);

        for (int i = 0; i < s; i++)
        {
            da->array[i] = temp[i];
            da->length++;
        }
        printf("\nNew size: %d, new length: %d", da->size, da->length);
    }
    da->array[da->length++] = elem;
    printf(" Current array length: %d\n", da->length);
}

void sort(struct dynamic_array *da)
{
    for (int i = 0; i < da->length; i++)
    {
        for (int j = 0; j < da->length; j++)
        {
            if (da->array[i] < da->array[j])
            {
                int temp = da->array[i];
                da->array[i] = da->array[j];
                da->array[j] = temp;
            }
        }
    }
}

void remove_from(struct dynamic_array *da, int index)
{
    for (int i = index; i < da->length - 1; i++)
    {
        da->array[i] = da->array[i + 1];
    }
    da->length--;
}

void remove_elem(struct dynamic_array *da, int elem)
{
    for (int i = 0; i < da->length; i++)
    {
        if (da->array[i] == elem)
        {
            remove_from(da, i);
        }
    }
}

void display(struct dynamic_array *da)
{
    printf("Size: %d, Length: %d", da->size, da->length);
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

    printf("\n");
    sort(&da);
    display(&da);

    printf("\n");
    remove_from(&da, 2);
    display(&da);

    printf("\n");
    remove_elem(&da, 21);
    display(&da);

    return 0;
}
