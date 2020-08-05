#include <stdlib.h>
#include <stdio.h>
//#include <cstring>
struct _node{
    char name[128];
    char mail[128];
    int  phnum;
    struct _node *nxt;
};
typedef struct _node node;
node *getnode()
{
       node *p;
       p=(node *)malloc(sizeof(node));

       if(p==NULL){
           printf("BUG!!!Empty dynamic pointer");
           exit(1);
          }
      return p;
}
void freenode(node *p)
{
    free(p);
}
void release(node *p)
{
    node *p1;
    p1=getnode();
    while(p!=NULL){
        p1=p->nxt;
        freenode(p);
        p=p1;
    }
    freenode(p1);
}


node *insert(node *head,node *p,node input){ 
    node *new_node;
    new_node=getnode();
    *new_node=input;
    new_node->nxt=NULL;
    if(p==NULL){
        new_node->nxt=head;
        head=new_node;
    }
    else{
        if(p->nxt == NULL){
            p->nxt=new_node;
        }
        else{
            new_node->nxt=p->nxt;
            p->nxt=new_node;
        }

    }
    return (head);
  }
void print_node(node *p){
    while(p !=NULL){
        printf("%s\n",p->name);
        printf("%s\n",p->mail);
        printf("%010d\n",p->phnum);
        p=p->nxt;
        puts("");
    }
}
node *find_node(node *head,char value[]){
    node *p;
    p=NULL;
    if(head==NULL){
        return p;
    }
    else{
        p=head;
        while(p != NULL){
            if(strcmp(p->name,value)==0){
                return p;
            }
            else{
                p=p->nxt;
            }
        }
    }
    return p;
}
node *delete_node(node *head,node *p){
    node *previous;
    previous=getnode();
    if(p==head){
        head=head->nxt;
    }
    else{
        previous=head;
        while(previous->nxt !=p){
            previous=previous->nxt;
        }
        if(p->nxt !=NULL){
            previous->nxt=p->nxt;
        }
        else{
            previous->nxt=NULL;
        }
    }
    return head;
}
int length(node *head){
    int num=0;
    node *p;
    p=head;
    while(p!=NULL){
        p=p->nxt;
        ++num;
    }
    return num;
}
int main(){
      node *head,*p,input;
      head=NULL;
      char string[128];
      int num;
      while(1){
          char c;
          scanf(" %c",&c);
          switch(c){
              case 'i':
                scanf("%128s",input.name);
                scanf("%128s",input.mail);
                scanf("%d",&input.phnum);
                p=head;
                if(head ==NULL){
                   head=insert(head,NULL,input);
                }
                else{
                    while(p->nxt!=NULL){
                        p=p->nxt;
                    }
                    head=insert(head,p,input);
                }
                break;
              case 'l':
                print_node(head);               
                break;
              case 'q':
                release(head);
                return 0;
                break;
              case 'f':
                scanf("%128s",string);  
                p=find_node(head,string);
                if(p ==NULL){
                    printf("Not found\n");
                }
                else{
                    printf("found\n");
                    printf("%s\n",p->name);
                    printf("%s\n",p->mail);
                    printf("%010d\n",p->phnum);
                }
                puts("");
                break;
              case 'd':
                scanf("%128s",string);
                p=find_node(head,string);
                if(p==NULL){
                    printf("Can not delete\n");
                }
                else{
                   
                    delete_node(head,p);
                    printf("Delete ok\n");
                }
                break;
               case 'h':
                 printf("%d\n",length(head));
                 break;
           }
          system("pause");
          system("cls");
      }
      return 0;
  }


