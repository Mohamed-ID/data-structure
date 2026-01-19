#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct linkedList
{
    int number;
    struct linkedList *next;
} linkedList;


typedef struct Queue
{
    linkedList *front;
    linkedList *tail;
    int size;
} Queue;


linkedList* create_node(int value);
void free_list(linkedList *headlist);



Queue *create_queue();
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
int peek(Queue *q);
int is_empty(Queue *q);
void free_queue(Queue *q);



int main()
{
    Queue *mainQueue = create_queue();

    if (is_empty(mainQueue)) printf("Queue is empty now.\n");
    
    enqueue(mainQueue, 8);
    enqueue(mainQueue, 3);
    enqueue(mainQueue, 4);
    enqueue(mainQueue, 6);
    enqueue(mainQueue, 8);
    enqueue(mainQueue, 1);

    printf("Front -> %d\nTail -> %d\n", mainQueue->front->number, mainQueue->tail->number);
    
    dequeue(mainQueue);
    dequeue(mainQueue);
    
    printf("After 2 Dequeue.\n");
    printf("Front -> %d\nTail -> %d\n", mainQueue->front->number, mainQueue->tail->number);

    int headVal = peek(mainQueue);

    printf("Peak value -> %d\n", headVal);

    free_queue(mainQueue);
}

// &Queue Method
Queue *create_queue()
{
    Queue *newQueue = malloc(sizeof(Queue));

    if (newQueue == NULL) {
        return NULL;
    }


    newQueue->front = NULL;
    newQueue->tail = NULL;
    newQueue->size = 0;

    return newQueue;
}

void enqueue(Queue *q, int value)
{
    linkedList *newNode = create_node(value);

    if (q->front == NULL && q->tail == NULL)
    {
        q->front = newNode;
        q->tail = newNode;
        q->size = 1;
        return;
    }

    q->tail->next = newNode;
    q->tail = newNode;
    q->size++;
}

int dequeue(Queue *q)
{
    if (q->front == NULL)
        return INT_MIN;

    int returnValue = q->front->number;

    if(q->front->next == NULL)
    {
        free(q->front);
        q->front = NULL;
        q->tail = NULL;
        q->size = 0;
        return returnValue;
    }

    linkedList *nextNode = q->front->next;
    
    free(q->front);
    q->front = nextNode;
    q->size--;

    return returnValue;
}

int peek(Queue *q)
{
    if(q->front == NULL)
        return INT_MIN;
    
    return q->front->number;
}

int is_empty(Queue *q)
{
    return q->front == NULL;
}

void free_queue(Queue *q)
{
    free_list(q->front);
    free(q);
}


// !List Method
void free_list(linkedList *headlist)
{
    linkedList *templist;
    
    while (headlist != NULL)
    {
        templist = headlist->next;
        free(headlist);
        headlist = templist;
    }
}

linkedList* create_node(int value)
{
    linkedList *newNode = malloc(sizeof(linkedList));

    if (newNode == NULL)
        return NULL;

    newNode->next = NULL;
    newNode->number = value;

    return newNode;
}