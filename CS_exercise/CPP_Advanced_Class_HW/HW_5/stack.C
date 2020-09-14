#include "stdlib.h"
#include "stdio.h"
struct stack_node_{
    int x;
    int y;
    struct stack_node_ *next;
};
typedef struct stack_node_ node;

node *path=NULL;

node *push(node *stack,int x,int y)
{
    node *new_node;
    new_node =(node *)malloc(sizeof(node));
    if(!new_node)
    {
        printf("Memory filled!");
        exit(1);
    }
    new_node->x=x;
    new_node->y=y;
    stack=new_node;
    return stack;
}
node *pop(node *stack, int *x, int *y){
    node *top;
    if(stack != NULL)
    {
        top = stack;
        stack = stack->next;
        *x=top->x;
        *y=top->y;
        free(top);
    }
    else
    {
        *x= -1;
        *y= -1;
    }
    return stack;
}
void walk(int maze[][10], int x, int y)
{
    while(1)
    {
        if(x==1 && y==1)
        {
            path= push(path,x,y);
            maze[y][x]=2;
            break;
        }
        maze[y][x]=2;
        if(maze[y-1][x]<=0)
        {
            path = push(path, x, y);
            y--;
        }
        else if(maze[y+1][x] <=0){
            path=push(path,x,y);
            y++;
        }
        else if(maze[y][x-1] <=0){
            path=push(path,x,y);
            x--;
        }
        else
        {
            maze[y][x]=3;
            path = pop(path,&x,&y);
        }
    }
}
int main()
{
    int i,j;
    int maze[7][10]=
    {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 1, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 1, 0, 1, 0, 1, 1, 0, 1,
		1, 0, 1, 0, 1, 1, 1, 0, 0, 1,
		1, 0, 1, 0, 0, 0, 0, 0, 1, 1,
		1, 0, 0, 0, 1, 1, 1, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    };
    walk(maze,8,5);
    for(i=0;i<7;i++){
        for(j=0;j<10;j++)
            printf("%d ",maze[i][j]);
        printf("\n");
    }
    system("pause");
    return 0;
}

