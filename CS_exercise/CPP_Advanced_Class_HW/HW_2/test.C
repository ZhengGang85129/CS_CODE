#include <cstring>
#include <stdio.h>
#include <stdlib.h>

char value[128];
char value2[128];
int main(){
scanf("%s",value);
scanf("%s",value2);
if(strcmp(value,value2)==0){
    printf("yes\n");
    printf("%s",value);
}
else{
    printf("false");
    printf("%s",value);
}
return 0;
}

