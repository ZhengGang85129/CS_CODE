#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct binary_tree_node{
    char name[128];
    char phone[20];
    struct binary_tree_node* left;
    struct binary_tree_node* right;
};
typedef struct binary_tree_node node;


void print_inorder(node *ptr){
    if(ptr != NULL){
        print_inorder(ptr->left);
        printf("Name: %s\n",ptr->name);
        printf("Phone: %s\n\n",ptr->phone);
        print_inorder(ptr->right);
    }
    else
        return;
}
void print_postorder(node *tree_node){
    if(tree_node != NULL){
        print_postorder(tree_node->left);
        print_postorder(tree_node->right);
        printf("Name: %s\n",tree_node->name);
        printf("Phone: %s\n\n",tree_node->phone);

    }
    else
        return;
}
void print_priororder(node *tree_node){
    if(tree_node !=NULL){
        printf("Name: %s \n",tree_node->name);
        printf("Phone: %s\n\n",tree_node->phone);
        print_priororder(tree_node->left);
        print_priororder(tree_node->right);
    }
    else 
        return ;
}
node *insert_node(node  *tree_node,node input){
    node *new_tree;
    node *current;
    node *parent;
    new_tree=(node *)malloc(sizeof(node));
    strcpy(new_tree->name,input.name);
    strcpy(new_tree->phone,input.phone);
    *new_tree = input;
    new_tree->left=NULL;
    new_tree->right=NULL;
    if(tree_node==NULL){
        tree_node=new_tree;
    }
    else{
        current=tree_node;
        while(current != NULL)
        {
            parent = current;
            if(strcmp(current->name,new_tree->name)>0)
                current=current->left;
            else
                current=current->right;
        }
        if(strcmp(parent->name,input.name)>0)
            parent->left=new_tree;
        else
            parent->right=new_tree;
    }
    return tree_node;
}

node *find_node(node* root,char input[]){
    node* ptr;
    ptr=root;
    while(ptr !=NULL){
        if(strcmp(ptr->name,input)>0)
           ptr=ptr->left;
        else if(strcmp(ptr->name , input)<0)
           ptr=ptr->right;
        else
           return ptr;
    }
    return NULL;
}
node *find_parent(node *ptr,char input[],int *pos){
    node *parent;
    parent=ptr;
    *pos=0;
    while(ptr != NULL){
        if(strcmp(ptr->name,input)==0){
            return parent;
        }
        else{
            parent=ptr;
            if(strcmp(ptr->name,input)>0 ){
                *pos=-1;
                ptr=ptr->left;
            }
            else{
                *pos=1;
                ptr=ptr->right;
            }
        }
    }
    return NULL;
}
node *delete_node(node *tree,char input[]){
    node *parent;
    node *ptr;
    node *next;
    int pos;
    parent=find_parent(tree,input,&pos);
    if(parent !=NULL)
    {
        switch(pos){
            case -1:
                ptr= parent->left;
                break;
            case 1:
                ptr=parent->right;
                break;
            case 0:
                ptr=parent;
                break;
        }
        if(ptr->left==NULL){
            if(parent==ptr)
                tree=tree->right;
            else{
                if(pos==1)
                    parent->right=ptr->right;
                else
                    parent->left=ptr->right;
            }
            free(ptr);
        }
        else if(ptr->right==NULL){
            if(parent==ptr)
                tree=tree->left;
            else{
                if(pos==1)
                    parent->right=ptr->left;
                else
                    parent->left=ptr->left;
            }
            free(ptr);
        }
        else{
            next=ptr->left;
            parent=ptr;
            if(next->right==NULL){
                ptr->left=next->left;
            }
            else{
                while(next->right !=NULL){
                    parent=next;
                    next=next->right;
                 }
                 parent->right=next->left;
            }
            strcpy(ptr->name,next->name);
            strcpy(ptr->phone,next->phone);
            free(next);
        }
    }
    return tree;
}
            
int main(){
    node* root;
    node* ptr;
    root=NULL;
    char op;
    node input;
    char name[128];
    while(1){ 
        scanf("%c",&op);
        switch(op){
             case 'i':
                scanf("%s",input.name);
                scanf("%s",input.phone);
                root=insert_node(root,input);
                break;
             case 'm':
                print_priororder(root);
                puts("");
                break;
             case 'n':
                print_postorder(root);
                puts("");
                break;
             case 'f':
                scanf("%s",name);
                ptr=find_node(root,input.name);
                if(ptr ==NULL)
                    printf("not found\n");
                else{
                    printf("found:\nName: %s\nPhone: %s\n\n",ptr->name,ptr->phone);
                }
                break;
             case 'l':
                if(root !=NULL){
                    print_inorder(root);
                }
                else{
                    printf("NULL \n");
                }
                puts("");
                break;
             case 'q':
                return -1;
                break;
             case 'd':
                scanf("%s",name);
                ptr=delete_node(root,name);
                if(ptr==NULL)
                    printf("cannot delete\n");
                else
                    printf("delete %s ok\n\n",name);
                break;    
                
            }
    }
    return 0;
}


