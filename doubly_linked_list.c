#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct LinkedList
{
    struct Node *head;
};

void add_node(struct LinkedList *list, int data)
{
    printf("Adding %d. ", data);
    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;

    if (list->head == NULL)
    {
        // list is empty
        list->head = temp;
    }
    else
    {
        struct Node *ptr = list->head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->prev = ptr;
    }
    printf("added element\n");
}

void remove_node(struct LinkedList *list, int key)
{
    printf("removing node. ");
    struct Node *ptr = list->head;

    if (ptr == NULL)
    {
        // list is empty
    }
    if (ptr->next == NULL)
    {
        // only one node
        list->head = NULL;
    }
    if (ptr->data == key)
    {
        // remove head node
        list->head = ptr->next;
        ptr->next->prev = list->head;
    }
    while (ptr->next->next != NULL)
    {
        // more than one node, but skips the last node
        if (ptr->next->data == key)
        {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
        }
        ptr = ptr->next;
    }
    if (ptr->next->data == key)
    {
        // checks last node
        ptr->next = NULL;
    }

    printf("removed node.\n");
}

void sort_list(struct LinkedList *list)
{
    printf("sorting. ");
    struct Node *ptr = list->head;
    struct Node *current;

    while (ptr->next != NULL)
    {
        // sort all nodes except first
        current = ptr;
        while (current->next->next != NULL)
        {
            if (current->next->data > current->next->next->data)
            {
                struct Node *temp = current->next;
                current->next = temp->next;
                temp->next->prev = current;

                temp->prev = current->next;
                temp->next = current->next->next;
                current->next->next = temp;
            }
            current = current->next;
        }
        ptr = ptr->next;
    }
    if (list->head->data > list->head->next->data)
    {
        // sort first node
        struct Node *temp = list->head;
        list->head = list->head->next;
        list->head->prev = NULL;

        ptr = list->head;
        while (ptr->next != NULL)
        {
            if (ptr->data > temp->data)
            {
                temp->next = ptr;
                temp->prev = ptr->prev;
                ptr->prev = temp;
                temp->prev->next = temp;
                break;
            }
            ptr = ptr->next;
        }
    }
    printf("sorted\n");
}

void display(struct LinkedList *list)
{
    struct Node *temp = list->head;
    while (temp->next != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
}

int main()
{
    struct LinkedList list;
    list.head = NULL;

    add_node(&list, 21);
    add_node(&list, 15);
    add_node(&list, 11);
    add_node(&list, 44);
    add_node(&list, 23);
    add_node(&list, 41);
    add_node(&list, 91);
    add_node(&list, 53);

    printf("\n");
    display(&list);

    printf("\n");
    sort_list(&list);
    display(&list);

    printf("\n");
    remove_node(&list, 11);
    display(&list);

    printf("\n");
    remove_node(&list, 41);
    display(&list);

    printf("\n");
    remove_node(&list, 91);
    display(&list);

    return 0;
}
