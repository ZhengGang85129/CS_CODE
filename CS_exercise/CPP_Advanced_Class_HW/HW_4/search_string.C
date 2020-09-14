#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#define N 6
#define s_length 128
void LinearSearch(int n,char (*p)[s_length],char value[s_length]){
	int i=0;
	int flag=0;
	while(i<n && flag==0){
		printf("%d: %s\n",i,p[i]);
		if(strcmp(p[i],value)==0){
			printf("found: %s\n",value);
			flag=1;
		}
		i++;
	}
	if(flag==0)
		printf("not found\n");
}
void BinarySearch(int n, char (*p)[s_length],char value[s_length]) 
{
    int low=0, high=n, mid,flag=0;
    while(low <= high && flag==0) 
    {
        mid = (low + high) / 2;
        printf("%d: %s\n", mid, p[mid]);
        if(strcmp(p[mid] , value) >0)
            high = mid - 1;
        else if(strcmp(p[mid],value)<0){
            low = mid+1;
        }
        else{
            printf("found: %s\n",value);
            flag=1;
            break;
        }
    }
    if(flag==0){
    	printf("not found\n");
	}
}
int insert(int cnt,char key[s_length],char (*array)[s_length]){
	strcpy(array[cnt],key);
	
}
void print(int n,char (*p)[s_length]){
	int i;
	for(i=0;i<n;i++){
		printf("%s ",p[i]);
	}
	puts("");
}

int main(int argc, char *argv[]) {
	int op;
	char array[400][s_length];
//	array=(char*)malloc(sizeof(char));
	char value[s_length];
	int n=0;
/*	printf("1 insert\n");
	printf("2 linear search\n");
	printf("3 bin search\n");
	printf("4 print\n");
	printf("5 exit\n");*/
	while(1){
		scanf("%d",&op);
		switch(op){
		case 1:
			scanf("%s",value);
			if(n==0){
				strcpy(array[0],value);
			}
			else{
				int j=n-1;
				strcpy(array[n],value);
				for(j=n-1;j>=0 && strcmp(array[j] , value)>0 ;j--){
					strcpy(array[j+1],array[j]);
				}
				strcpy(array[j+1], value);
			}
			++n;
			break;
		case 2:
			scanf("%s",value);
			LinearSearch(n,array,value);
			break;
		case 3:
			scanf("%s",value);
			BinarySearch(n,array,value); 
			break;
		case 4:
			print(n,array);
			break;
		case 5:
			return 0;
			break;
		}
	}
	return 0;
}
