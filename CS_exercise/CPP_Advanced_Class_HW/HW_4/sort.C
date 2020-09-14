#include <stdlib.h>
#include <stdio.h>
#define N 6
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void swap(int *a, int *b){
	int intermediate;
	intermediate = *a;
	*a=*b;
	*b=intermediate;
}
void print(int n,int *p){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",p[i]);
	}
	puts("");
}
void bubble_sort(int n,int *data){
	int i, j; 
    for(i=n; i>1; i--) 
    {
        for(j=0; j<i-1; j++)
        {
            if(data[j+1] < data[j]) 
            {
               swap(&data[j+1], &data[j]);
            }
        }
        print(N,data);
    }
}
void selection_sort(int n,int *data){
	int i, j, pos; 
    for(i=0; i<n-1; i++)
    {
        pos = i;
        for(j=i+1; j<n; j++) 
        {
            if(data[j] < data[pos]) 
                pos = j; 
        }
        swap(&data[i], &data[pos]);
        print(N,data);
    }
}
void insertion_sort(int n,int *data){
	int i, j; 
    int key;
    for( i=1; i<n; i++) 
    {
        key=data[i];
        for(j=i-1; j>=0 && data[j]>key; j--)
        {
            data[j+1] = data[j];
        }
        data[j+1] = key;
        print(N,data);
    }
}
void quicksort(int *A,int low,int high){
    int pivot;
    int a,b;
    a=low+1;
    b=high;
    pivot=A[low];
    do{
        while(A[a]<pivot && a<high)
            a++;
        while(A[b]>pivot && b>=0)
            b--;
        if(a<b)
            swap(&A[a],&A[b]);
        print(N,A);
    }while(a<b);
    A[low]=A[b];
    A[b]=pivot;
    if(b-1>low){
        quicksort(A,low,b-1);
    }
    if(b+1<high){
        quicksort(A,b+1,high);
    }
}
int main(int argc, char** argv) {
	int array[N];
	int i;
	for(i=0;i<N;i++){
		scanf("%d",&array[i]);
	}
	int op;
    int j=0;
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
        case 4:
            quicksort(array,0,N-1);
            break;
	}
	print(N,array);
	return 0;
}
