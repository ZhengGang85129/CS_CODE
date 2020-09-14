#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CARD 52
#define NUMBER 13
#define SUIT 4
#define PEOPLE 4

#define MAX_SIZE 52


int stack[MAX_SIZE];
int top=-1;


int push(int value)
{
	if( top == MAX_SIZE-1 )
	{
		return -1;
	}
	top++;
	stack[top] = value;
	return 1;
}


int pop()
{
	int temp;

	if( top == -1 ) //?????????
	{
		return -1;
	}
	temp = stack[top];
	stack[top] = 0;
	top--;
	return temp;
}

void InsertionSort(int n, int *data)
{
	int i, j, key;
    for( i=1; i<n; i++) 
    {
        key=data[i];
        for(j=i-1; j>=0 && data[j]>key; j--)
        {
            data[j+1] = data[j];
        }
        data[j+1] = key;  //?key??
    }
}

void reshuffle()
{
	int pos;
	int i;
	int card[CARD]={0};
	srand(time(NULL));
	int ary[CARD]={0};
    int j;
    int dim=CARD;
    
    for(j=0;j<CARD;j++){
        ary[j]=j+1;
    }
    /*
	for(i=0;i<CARD;i++)
	{
		pos = rand()%dim;
		card[i]=ary[pos];
        ary[pos]=ary[dim-1];
        dim--;
	}*/
    i=0;
	while(i!=CARD)
	{
		pos = rand()%CARD;
	    push(ary[pos]);
        ary[pos]=ary[dim-1];
        dim--;
        i++;
	}
}


void displayCard(int n, int *card)
{
	int i;
	int array[4]={5,4,3,6};
		
	printf("Player%d:\n", n+1);
	for(i=0; i<CARD/PEOPLE; i++)
	{
		printf("[%c%2d] ", array[card[i]/NUMBER], card[i]%NUMBER+1);
	}
	printf("\n");
}


int main()
{

	int i, j;
	int player[PEOPLE][CARD/PEOPLE];

	reshuffle();
    
	for(i=0; i<CARD/PEOPLE; i++)
	{
		for(j=0; j<PEOPLE; j++)
		{
			player[j][i] = pop();
//            printf("%d ",player[j][i]);
		}
	}


	for(i=0; i<PEOPLE; i++)
		displayCard(i, player[i]);
	printf("\n");


	for(i=0; i<PEOPLE; i++)
	{
		InsertionSort(CARD/PEOPLE, player[i]);
		displayCard(i, player[i]);
	}
	system("pause");
	return 0;
}
