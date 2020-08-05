#include <stdlib.h>
#include <stdio.h>

struct _node{
    int data;
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
        printf("%d ",p->data);
        p=p->nxt;
    }
    puts("");
}
node *find_node(node *head,int num){
    node *p;
    p=NULL;
    if(head==NULL){
        return p;
    }
    else{
        p=head;
        while(p != NULL){
            if(p->data == num){
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
    freenode(p);
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
node *jnsert(node *head,node input){
    node *previous;
    previous=getnode();
    *previous=input;
    previous->nxt=head;
    head=previous;
    return previous;
}
node *sortnode(node *head,node input){
    node *p,*new_node;
    new_node=getnode();
    new_node->data=input.data;
    new_node->nxt=NULL;
    p=head;
    if(p->data > new_node->data)
    {
        new_node->nxt=p;
        return head= new_node;
    }
    else{
    while(p->nxt != NULL){
        if(p->nxt->data < new_node->data){
            p=p->nxt;
        }
        else{
            new_node->nxt=p->nxt;
            p->nxt=new_node;
            return head;
        }
    }
    }
    p->nxt=new_node;
    return head;
}
int main(){
      node *head,*p,input,*previous;
      head=NULL;
      previous=(node *)malloc(sizeof(node));
      int num;
      while(1){
          char c;
          scanf(" %c",&c);
          switch(c){
              case 'i':
                scanf("%d",&input.data);
                if(head ==NULL){
                   head=insert(head,NULL,input);
                   p=head;
                }
                else{
                    head=insert(head,p,input);
                    p=p->nxt;
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
                scanf("%d",&num);  
                if(find_node(head,num) ==NULL){
                    printf("Not found\n");
                }
                else{
                    printf("found %d\n",num);
                }

                break;
              case 'd':
                scanf("%d",&num);
                p=find_node(head,num);
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
               case 'n':
                    scanf(" %d",&num);
                    p=find_node(head,num);
                    if(p == NULL){
                        printf("%d not found, can not insert\n",num);
                    }
                    else{
                        scanf("%d",&input.data);
                        insert(head,p,input);
                    }
                 break;
               case 'm':
                 scanf("%d",&num);
                 p=head;
                 scanf("%d",&input.data);
                 if(num > length(head)){
                     while(p->nxt !=NULL){
                         p=p->nxt;
                     }
                     insert(head,p,input);
                 }
                 else{
                     if(num==0){
                       head=jnsert(head,input);
                     }
                     else{
                     int cnt=1;
                     while(cnt < num){
                         ++cnt;
                         p=p->nxt;
                     }
                     insert(head,p,input);
                     }
                 }
                 break;
               case 'j':
                 scanf("%d",&input.data);
                 if(head==NULL){
                     head=insert(head,NULL,input);
                     p=head;
                 }
                 else{
                  head=jnsert(head,input);  
                 }
                 break;
               case 's':
                scanf("%d",&input.data);
                if(head==NULL){
                    head=insert(head,NULL,input);
                    p=head;}
                else{
                head=sortnode(head,input);
                }
                break;

           }
//           system("read var1");
//           system("clear");
      }
      return 0;
  }


