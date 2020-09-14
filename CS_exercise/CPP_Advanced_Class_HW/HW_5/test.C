#include <stdlib.h>
#include <stdio.h>
int main(){
int *p,a=5;
*p=a;
printf("%d\n",*p);
free(p);
printf("%d\n",*p);
return 0;
}
