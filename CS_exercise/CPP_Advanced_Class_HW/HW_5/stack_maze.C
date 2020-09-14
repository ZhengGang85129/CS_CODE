#include <stdio.h>
#include <stdlib.h>

// ???????
struct stack_node 
{
	int x;
	int y;
	struct stack_node *next;
};
typedef struct stack_node node;

node *path = NULL;

// ???????
node *push(node *stack, int x, int y)
{
     
	node *new_node;	
	new_node = (node *)malloc(sizeof(node));	
	
	//????????
	
	if(new_node==NULL) 
	{
		printf("!\n");
		//exit(0);
    }
	
	new_node->x = x;
	new_node->y = y;
	new_node->next = stack;
	stack = new_node;
	
	return stack;
	
}


//???????
node *pop(node *stack, int *x, int *y)
{
	node *top;

	if( stack != NULL ) //?????????
	{
		top = stack;
		stack = stack->next;
		*x = top->x;
		*y = top->y;
		free(top);
	}
	else 
	{
		*x = -1;
		*y = -1;
	}
	return stack;
}


void walk(int maze[][10], int x, int y)
{
	while(1)
	{
		if(x==1 && y==1) // ?????
		{
			path = push(path, x, y);
			maze[y][x] = 2; // ??????
			break;
		}
		maze[y][x] = 2; // ???????
		if( maze[y-1][x] <= 0 ) // ????
		{
			path = push(path, x, y);
			y--;
		}
		else if( maze[y+1][x] <= 0 ) // ????
		{
			path = push(path, x, y);
			y++;
		}
		else if( maze[y][x-1] <= 0 ) // ????
		{
			path = push(path, x, y);
			x--;
		}
		else if( maze[y][x+1] <= 0 ) // ????
		{
			path = push(path, x, y);
			x++;
		}
		else // ???? => ??
		{
			maze[y][x] = 3;
			path = pop(path, &x, &y); // ????
		}
	}
}
void print_path(node *ptr){
	
	if(ptr !=NULL){
		print_path(ptr->next);
		printf("[ %d, %d]\n",ptr->x,ptr->y);
		
	}
}

// ???
int main()
{
	// ??
	int i, j;
	node *ptr;
	// ??
	int maze[15][10] = // x=10, y=7
	{
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 
		1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 
		1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 
		1, 0, 1, 0, 0, 0, 0, 0, 1, 1,
		1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 
		1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 0, 0, 1,
        1, 1, 1, 0, 1, 1, 1, 0, 1, 1,
        1, 0, 0, 0, 0, 0, 1, 0, 1, 1,
        1, 0, 1, 1, 1, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
        1, 1, 1, 1, 1, 1, 0, 1, 0, 1,
        1, 1, 1, 1, 1, 1, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1
	};

	// ??
	walk(maze, 8, 13);

	// ??
	printf("maze:\n");
	
	for(i=0; i<15; i++)
/*    int maze[7][10] = // x=10, y=7
    {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 1, 0, 1, 0, 0, 0, 0, 1,
        1, 0, 1, 0, 1, 0, 1, 1, 0, 1,
        1, 0, 1, 0, 1, 1, 1, 0, 0, 1,
        1, 0, 1, 0, 0, 0, 0, 0, 1, 1,
        1, 0, 0, 0, 1, 1, 1, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    };

    // ??
    walk(maze, 8, 5);

    // ??
    printf("maze:\n");

    for(i=0; i<7; i++)*/
	{
		for(j=0; j<10; j++)
			printf("%d ", maze[i][j]);
		printf("\n");
	}	
	ptr=path;
	printf("path:\n");
	
	
	print_path(path);
	// ??
	system("pause");
	return 0;
}
