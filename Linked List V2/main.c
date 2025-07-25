#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList
{
    int number;
    struct linkedList *next;
} linkedList;


void free_list(linkedList *headlist);
linkedList* create_node(int value);
void append_node(linkedList **head, int value);
void prepend_node(linkedList **head, int value);
int list_length(linkedList *head);
int delete_node(linkedList **head, int value);
void print_list(linkedList *head);
int insert_at_position(linkedList **head, int value, int position);
void reverse_list(linkedList **head);
void reverse_list_iter(linkedList **head);





int main() {
    linkedList *head = create_node(5);
    linkedList **head_ptr = &head;
    
    append_node(head_ptr, 9);
    append_node(head_ptr, 4);

    print_list(head);
    
    prepend_node(head_ptr, 5);
    prepend_node(head_ptr, 8);
    prepend_node(head_ptr, 1);

    print_list(head);
    
    delete_node(head_ptr, 5);
    delete_node(head_ptr, 8);
    
    print_list(head);
    
    printf("list length: %d\n", list_length(head));
    
    insert_at_position(head_ptr, 7, -1);
    insert_at_position(head_ptr, 7, 4);
    insert_at_position(head_ptr, 12, 0);
    insert_at_position(head_ptr, 41, 2);
    
    print_list(head);
    printf("list length: %d\n", list_length(head));
    
    reverse_list(head_ptr);
    
    print_list(head);

    delete_node(head_ptr, 7);
    delete_node(head_ptr, 4);
    delete_node(head_ptr, 9);
    delete_node(head_ptr, 5);
    delete_node(head_ptr, 41);
    
    reverse_list(head_ptr);
    
    print_list(head);

    free_list(head);
}



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

void append_node(linkedList **head, int value)
{
    linkedList *newNode = create_node(value);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    linkedList *tempNode = *head;
    while (tempNode->next != NULL)
    {
        tempNode = tempNode->next;
    }
    
    tempNode->next = newNode;
}

void prepend_node(linkedList **head, int value)
{
    linkedList *newNode = create_node(value);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    linkedList *tempNode = *head;

    newNode->next = tempNode;
    *head = newNode;
}

int list_length(linkedList *head)
{
    int len = 0;

    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    
    return len;
}

int delete_node(linkedList **head, int value)
{
    linkedList *tempNode = *head;
    linkedList *prevNode;

    if (tempNode == NULL)
    {
        return 0;
    }

    if (tempNode->number == value)
    {
        *head = tempNode->next;
        free(tempNode);
        return 1;
    }

    prevNode = tempNode;
    tempNode = tempNode->next;
    

    while (tempNode != NULL)
    {
        if (tempNode->number == value)
        {
            prevNode->next = tempNode->next;
            free(tempNode);
            return 1;
        }

        prevNode = tempNode;
        tempNode = tempNode->next;
    }
    
    return 0;
}

void print_list(linkedList *head)
{
    if (head == NULL)
    {
        printf("[]\n");
        return;
    }
    
    printf("[");
    while (head != NULL)
    {
        printf("%d", head->number);
        if (head->next != NULL)
        {
            printf(" -> ");
        }
        
        head = head->next;
    }
    printf("]\n");
}

int insert_at_position(linkedList **head, int value, int position)
{
    linkedList *tempNode = *head;
    int length = list_length(tempNode);

    if (tempNode == NULL)
        return 0;

    if (length < position || 0 > position)
        return 0;
    
    if (length == position)
    {
        append_node(head, value);
        return 1;
    }

    if (position == 0)
    {
        prepend_node(head, value);
        return 1;
    }
    

    int current_pos = 1;
    linkedList *prevNode = tempNode;
    tempNode = tempNode->next;


    while (current_pos != position)
    {
        if (tempNode == NULL)
            return 0;

        prevNode = tempNode;
        tempNode = tempNode->next;
        current_pos++;
    }
    
    linkedList *newNode = create_node(value);

    prevNode->next = newNode;
    newNode->next = tempNode;

    return 1;
}

void reverse_list(linkedList **head)
{
    linkedList *prevNode = NULL;
    linkedList *currNode = *head;
    linkedList *nextNode = NULL;
    

    while (currNode != NULL)
    {
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }

    *head = prevNode;
}