#include <stdio.h>
#include <stdlib.h>

#define false 0;
#define true 1;

typedef struct
{
    int *array;
    int capacity;
    int size;
} Stack;

Stack *create_stack(int capacity);
void free_stack(Stack *stack);
int isFull(Stack *stack);
int isEmpty(Stack *stack);
int pop(Stack *stack);
int push(Stack *stack, int value);
int peek(Stack *stack);


int main()
{
    Stack *arr = create_stack(8);

    if (arr == NULL)
    {
        printf("arr uncreated!");
        return 0;
    }

    push(arr, 5);
    push(arr, 55);
    push(arr, 24521);
    push(arr, 1);
    
    if(isEmpty(arr)) 
        printf("stack is empty");
    
    
    for (int i = 0; i < arr->size; i++)
    {
        printf("%d ", arr->array[i]);
    }
    
    printf("\n");
    printf("poped value: %d\n", pop(arr));
    
    for (int i = 0; i < arr->size; i++)
    {
        printf("%d ", arr->array[i]);
    }
    
    printf("\nsize array: %d", arr->size);

    int peek_val = peek(arr);
    
    printf("\npeek value: %d", peek_val);

    free_stack(arr);
}


Stack *create_stack(int capacity)
{
    if(capacity <= 0)
        return NULL;
    
    Stack *stack = malloc(sizeof(Stack));

    if(stack == NULL)
        return NULL;

    stack->array = malloc(capacity * sizeof(int));

    if(stack->array == NULL)
    {
        free(stack);
        return NULL;
    }

    stack->size = 0;
    stack->capacity = capacity;

    return stack;
}


void free_stack(Stack *stack)
{
    free(stack->array);
    free(stack);
}


int isFull(Stack *stack) 
{
    if (stack->capacity == stack->size)
    {
        return true;
    }
    
    return false;
}


int isEmpty(Stack *stack)
{
    if (stack->size == 0)
    {
        return true;
    }
    
    return false;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
        return false;
    

    return stack->array[--stack->size];
    
}


int push(Stack *stack, int value)
{
    if(isFull(stack))
        return false;

    stack->array[stack->size] = value;

    stack->size++;
    return true;
}

int peek(Stack *stack)
{
    if (isEmpty(stack))
        return false;

    return stack->array[stack->size - 1];
}