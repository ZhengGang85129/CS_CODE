#include <stdlib.h>
#include <stdio.h>

struct tree_node_
{
	int data;
	struct tree_node_ *left;
	struct tree_node_ *right;
};
typedef struct tree_node_ node;

node *insert_node(node *tree,node input){
	node *current,*parent;
    node *new_node;
    new_node=(node *)malloc(sizeof(node));
    *new_node=input;
    if(tree ==NULL){
		tree=new_node;
	}	
	else{
		current=tree;
		while(current!=NULL){
			parent=current;
			if(current->data > new_node->data){
				current = current->left;
			}
			else
                current=current->right;
		}
		if(parent->data >new_node->data){
			parent->left=new_node;
		}
		else{
			parent->right=new_node;
		}
        
	}

	return tree;
}
void print_inorder(node *tree){
	if(tree!=NULL){
		print_inorder(tree->left);
		printf("%d ",tree->data);
		print_inorder(tree->right);
	}
	else
		return ;
}
void print_preorder(node *tree){
	if(tree !=NULL){
		printf("%d ",tree->data);
		print_preorder(tree->left);
		print_preorder(tree->right);
		
	}
}
void print_postorder(node *tree){
	if(tree !=NULL){
		print_postorder(tree->left);
		print_postorder(tree->right);
		printf("%d ",tree->data);
	}
}
node *find_parent(node *ptr, node input, int *pos)
{
	node *parent;
	parent = ptr;	// �qptr�}�l��
	*pos = 0;
	while(ptr != NULL)	
	{
		if(ptr->data == input.data){
            return parent;
        }
        else
        {
            parent=ptr;
            if(ptr->data > input.data)
            {
                    *pos =-1;
                    ptr=ptr->left;
            }
            else
            {
                *pos =1;
                ptr=ptr->right;
            }
        }
    }
	return NULL;	// �䤣��
}

// �R���`�I
node *delete_node(node *root, node input)
{
	node *parent;
	node *current;
	node *next;
	int pos,flag=0;
	parent = find_parent(root, input, &pos);
	if(parent !=NULL)
	{
		switch(pos)	// �P�_�ثe�`�I�A���`�I����Υk��
		{
			case -1:
				current = parent->left;
				break;
			case 1:
				current = parent->right;
				break;
			case 0:
				current = parent;
				break;
		}
		if(current->left == NULL)
		{
			if(parent==current){
				root = root->right;
            }
			else				// ��L
			{
				if( pos == 1 )
				{
					parent->right = current->right;
				}
				else
				{
					parent->left = current->right;
				}
			}
            free(current);
		}
		else if(current->right == NULL)	
		{
			if(parent != current)
			{
				if( pos == 1 )
				{
					parent->right = current->left;
				}
				else
				{
					parent->left = current->left;
				}
			}
			else
				root = root->left;
            free(current);
		}
		else		
		{
			parent = current;
			next = current->left;	
			if(next->right != NULL){
				while(next->right != NULL)	
				{
					parent = next;		
					next = next->right;
				}
				parent->right = next->left; 
			}
			else{
				current->left=next->left;
			}
			parent->data = next->data;	
			free(next);	
		}
    return root;
    }
    

}
node *find_node(node *ptr,node input){
	while(ptr != NULL){
		if(ptr->data ==input.data){
			return ptr;
		}
		else{
			if(ptr->data > input.data){
				ptr=ptr->left;
			}
			else{
				ptr=ptr->right;
			}
		}
	}
	return NULL;
}
int main(int argc, char *argv[]){
	node *root;
	root=NULL;
	char op;
    node input;
    input.left=NULL;
    input.right=NULL;
	node *ptr;
	while(1){
		scanf("%c",&op);
		switch(op){
			case 'i':
				scanf("%d",&input.data);	
				root=insert_node(root,input);
         
				break;
			case 'l':
				print_inorder(root);
				puts("");
				break;
			case 'm':
				print_preorder(root);
				puts("");
				break;
			case 'n':
				print_postorder(root);
				puts("");
				break;
			case 'q':
				return 0;
				break;
			case 'f':
				scanf("%d",&input.data);
				ptr=find_node(root,input);
				if(ptr==NULL){
					printf("not found\n");
				}
				else{
					printf("found: %d\n",ptr->data);
				}
				break;
			case 'd':
				scanf("%d",&input.data);
				root=delete_node(root,input);
				if(ptr==NULL){
					printf("cannot delete\n");
				}
				else{
					printf("delete %d ok\n",input.data);
				}
				break;
		}
	}
	return 0;
}
