#include <string.h>
#include <stdlib.h>
#include <stdio.h>




int main(){
    char test[129];
    char test2[2][129];
    
    scanf("%s",test2[0]);
    scanf("%s",test2[1]);
    strcpy(test,test2[1]);
    printf("%s",test);




    return 0;
}

