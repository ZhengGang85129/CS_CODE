#include <stdio.h>
#include <stdlib.h>

int comb(int n, int m, int flag[],int N, int M){
	if(n==m || m==0){
		return 1;
	}
	if(n-m==1){
		return n;
	}

//	if(*(flag+(N-n)*(N-n+1)/2+M-m)){
//		return*(flag+(N-n)*(N-n+1)/2+M-m);
//	}
	
	int a =comb(n-1,m,flag,N,M);
	int b =comb(n-1,m-1,flag,N,M);
	return a+b;
	
}
int main(int argc, char *argv[]){
	int N,M;
	scanf("%d",&N);
	scanf("%d",&M);
	int *flag,n=4;
	flag=(int*)malloc(sizeof(int)*n);
	if(N>=M){
		printf("%d\n",comb(N,M,flag,N,M));
	}
	else if(N < M){
		printf("input error\n");
	}
	return 0;
	
}
