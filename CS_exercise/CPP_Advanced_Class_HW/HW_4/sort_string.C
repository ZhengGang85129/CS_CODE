#include <stdlib.h>
#include <stdio.h>
//#include <string.h>
#define N 6
#define MAX_SIZE_STRING 128
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void swap(char a[][MAX_SIZE_STRING], char b[][MAX_SIZE_STRING]){
	char intermediate[MAX_SIZE_STRING];
	strcpy(intermediate,*a);
    strcpy(*a,*b);
	strcpy(*b,intermediate);
}
void print(int n,char array[][MAX_SIZE_STRING]){
	int i;
	for(i=0;i<n;i++){
		printf("%s ",array[i]);
	}
	puts("");
}
void bubble_sort(int n,char data[][MAX_SIZE_STRING]){
	int i, j; 
    for(i=n; i>1; i--) 
    {
        for(j=0; j<i-1; j++)
        {
            if(strcmp(data[j+1],data[j])>0) 
            {
               swap(&data[j+1], &data[j]);
            }
        }
       print(N,data);
    }
}
void selection_sort(int n,char data[][MAX_SIZE_STRING]){
	int i, j, pos; 
    for(i=0; i<n-1; i++)
    {
        pos = i;
        for(j=i+1; j<n; j++) 
        {
            if(strcmp(data[j],data[pos])>0) 
                pos = j; 
        }
        swap(&data[i], &data[pos]);
        print(N,data);
    }
}
void insertion_sort(int n,char (*data)[MAX_SIZE_STRING]){
	int i, j; 
    char key[MAX_SIZE_STRING];
    for( i=1; i<n; i++) 
    {
        strcpy(key,data[i]);
        for(j=i-1; j>=0 && strcmp(data[j],key)<0; j--)
        {
            strcpy(data[j+1],data[j]);
        }
        strcpy(data[j+1],key);
        print(N,data);
    }
}
int main(int argc, char** argv) {
	char array[N][MAX_SIZE_STRING];
	int i;
	for(i=0;i<N;i++){
		scanf("%s",array[i]);
	}
	int op;
	scanf("%d",&op);
	switch(op){
		int k,j,pos;
		case 1:
	    	bubble_sort(N,array);
    		break;
    	case 2:
         	selection_sort(N,array);
    		break;
    	case 3:
    		insertion_sort(N,array);
    		break;
	}
    print(N,array);
   // printf("%s \n",array[2]);
	return 0;
}
