#include <stdlib.h>
#include <stdio.h>

struct _node{
	int data; //data 
	struct _node *nxt;//to connect data to data
};

typedef struct _node node;


int main(){
	node *head,*p;
	
    head=NULL;
    int value;

    while(1){
        scanf("%d",&value);
        if(value == -1){
            break;
        }
        else{
            if(head ==NULL){
                head=(node *)malloc(sizeof(node));
                p = head;
            }
            else{
                p->nxt=(node *)malloc(sizeof(node));
                p=p->nxt;
             }
        }
        
        p->data = value;
        p->nxt = NULL;
    }



  //  head=(node *)malloc(sizeof(node));//construct an dynamic space of node type for head;
    //	p=head;//assign the space to pointer p;
    p=head;

    while(p !=NULL){
        printf("%d\n",p->data);
        p=p->nxt;
    }
    puts("\n");
}

