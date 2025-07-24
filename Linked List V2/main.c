#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} linkedList;


int main() {
    linkedList *head = malloc(sizeof(linkedList));
    head->data = 1;
    head->next = NULL;
    printf("%d\n", head->data);
    printf("%d\n", head->next);
}