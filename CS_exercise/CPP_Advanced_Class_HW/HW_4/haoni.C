#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void hanoi (int n, char from, char mid, char to,int *a)
{  
    if(n==0)
        return ;
    a[n-1]++;
	hanoi(n-1,from, to, mid,a);
    printf("plate %d from %c -> %c\n",n,from,to);
    hanoi(n-1,mid, from, to,a);
}

int main()
{
    int n,i;
    int *a;
    int c=0;
    scanf("%d", &n);
    a=(int*)calloc(n,sizeof(int));
    memset(a,0,n);
    hanoi(n, 'A','B','C',a);
    int cnt;
    puts("");
	for(cnt=0;cnt<n;cnt++){
		printf("plate %d = %d\n",cnt+1,a[cnt]);
	}
    return 0;
}
