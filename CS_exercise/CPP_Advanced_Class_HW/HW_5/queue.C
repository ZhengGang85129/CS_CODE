#include <stdio.h>
#include <stdlib.h>

struct queue_node{
    int data;
    struct queue_node *next;
};
typedef struct queue_node node;
node *front = NULL;
node *rear = NULL;

int enqueue(int value)
{
    node *new_node;
    new_node = (node *)malloc(sizeof(node));
    if( !new_node)
    {
        node *new_node;

        new_node = (node *)malloc(sizeof(node));

