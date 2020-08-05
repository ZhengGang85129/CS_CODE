#include <stdio.h>
#include <stdlib.h>
#define R 3
#define C 3
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 
int main(int argc, char *argv[]) {
    int a[R][C] = {1,2,3,4,5,6,7,8,9};
    int b[R][C] = {2,4,6,8,10,12,14,16,18};
    int c[R][C] = {0};
    int i,j,k;
    for(i=0;i<R;i++){
        for(j=0;j<C;j++){
            for(k=0;k<C;k++){
                c[i][j] += a[i][k]*b[k][j];
            }
            printf("%-5d",c[i][j]);
        }
        printf("\n");
    }
 
    return 0;
}
