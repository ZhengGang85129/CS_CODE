#include <stdlib.h>
#include <stdio.h>

struct _node{
	int data; //data 
	struct _node *nxt;//to connect data to data
};

typedef struct _node node;


int main(){
	node *head=NULL,*p,*p2;
    int value;
    int cnt=0;
    while(cnt<5){
        scanf("%d",&value);
        ++cnt;
        //if(value == -1){
        //    break;
        //}
//        else{
            if(head ==NULL){
                head=(node *)malloc(sizeof(node));
                p = head;
                p->data = value;
                p->nxt=NULL;
            }
            else{
                head=(node *)malloc(sizeof(node));
                head->nxt=p;
                p=head;
                p->data=value;
             }
  //      }
    }



  //  head=(node *)malloc(sizeof(node));//construct an dynamic space of node type for head;
    //	p=head;//assign the space to pointer p;
    p=head;

    while(p !=NULL){
        printf("%d ",p->data);
        p=p->nxt;
    }
    p = head;
    while(p !=NULL){
        p2=p->nxt;
        free(p);
        p=p2;
    }
    return 0;
}

