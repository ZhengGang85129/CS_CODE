#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct tree_node_
{
	char name[128];
    char phone[128];
	struct tree_node_ *left;
	struct tree_node_ *right;
};
typedef struct tree_node_ node;

node *insert_node(node *tree,node input){
	node *new_node;
    node *current;
    node *parent;
	new_node=(node *)malloc(sizeof(node));
	*new_node=input;
	new_node->left=NULL;
	new_node->right=NULL;
	if(tree ==NULL){
		tree=new_node;
	}	
	else{
		current=tree;
		while(current!=NULL){
			parent=current;
			if(strcmp(current->name , input.name)>0){
				current = current->left;
			}
			else{
				current = current->right;
			}
		}
		if(strcmp(parent->name ,input.name)>0){
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
		printf("Name: %s\n",tree->name);
        printf("Phone: %s\n\n",tree->phone);
		print_inorder(tree->right);
	}
}
void print_preorder(node *tree){
	if(tree !=NULL){
		printf("Name: %s\n",tree->name);
        printf("Phone: %s\n\n",tree->phone);
		print_preorder(tree->left);
		print_preorder(tree->right);
		
	}
}
void print_postorder(node *tree){
	if(tree !=NULL){
		print_postorder(tree->left);
		print_postorder(tree->right);
		printf("Name: %s\n",tree->name);
        printf("Phone: %s\n\n",tree->phone);
	}
}
/*
node *search_node(node *ptr,int value){
	node *tmp;
	if(ptr != NULL){
		if(ptr->data == value){
			return ptr;
		}
		else{
			tmp=search_node(ptr->left,value);
			if(ptr!=NULL){
				return tmp;
			}
			tmp=search_node(ptr->right,value);
			if(ptr!=NULL){
				return tmp;
			}
		}
	}
	else{
		return NULL;
	}
}*/
node *find_parent(node *ptr, node input, int *pos)
{
	node *parent;
	parent = ptr;	// �qptr�}�l��
	*pos = 0;
	while(ptr != NULL)	
	{
		if(strcmp(ptr->name , input.name)==0)	// ���ؼ�
			return parent;		// �^�Ǧ��`�I�����`�I
		else
		{
			parent = ptr;
			if(strcmp(ptr->name , input.name)>0)
			{
				*pos = -1;			// ptr�bparent���l��
				ptr = ptr->left;	// ������
			}
			else
			{
				*pos = 1;			// ptr�bparent�k�l��
				ptr = ptr->right;	// ���k��
			}
		}
	}
	return NULL;	// �䤣��
}

// �R���`�I
node *delete_node(node *root, node input)
{
	node *parent;
	node *ptr;
	node *next;
	int pos;
	parent = find_parent(root, input, &pos);	// �qroot�}�l,��value�����`�I
    if(parent ==NULL)
        return NULL;
    else	// �����, �ǳƧR��
	{
		switch(pos)	// �P�_�ثe�`�I�A���`�I����Υk��
		{
			case -1:
				ptr = parent->left;
				break;
			case 1:
				ptr = parent->right;
				break;
			case 0:
				ptr = parent;
				break;
		}
		if(ptr->left == NULL)		// ���p1: �`�I�S�����l�� �p�G�n�R���O�ڸ`�I
		{
			if(parent == ptr)	// �p�G�n�R���O�ڸ`�I
				root = root->right;
			else				// ��L
			{
				if( pos == 1 )
				{
					//�n�R�����`�I�b���`�I�k��,�ҥH�N���`�I���k�`�I���V�R���`�I���k�`�I
					parent->right = ptr->right;
				}
				else
				{
					//�n�R�����`�I�b���`�I����,�ҥH�N���`�I�����`�I���V�R���`�I���k�`�I
					parent->left = ptr->right;
				}
			}
			free(ptr);
      //      free(parent);
		}
		else if(ptr->right == NULL)	// ���p2: �`�I�S���k�l��
		{
			if(parent != ptr)
			{
				if( pos == 1 )
				{
					//�n�R�����`�I�b���`�I�k��,�ҥH�N���`�I���k�`�I���V�R���`�I�����`�I
					parent->right = ptr->left;
				}
				else
				{
					//�n�R�����`�I�b���`�I����,�ҥH�N���`�I�����`�I���V�R���`�I�����`�I
					parent->left = ptr->left;
				}
			}
			else
				root = root->left;
			free(ptr);
		}
		else						// ���p3: �`�I�����k�l��
		{
			parent = ptr;
			next = ptr->left;	// ����N�Inext, �qptr����}�l��
			if(next->right != NULL){
				while(next->right != NULL)	// �����l�`�I���k�l���̤j�ȷ���N�I
				{
					parent = next;		// parent��next�����`�I
					next = next->right;
				}
				parent->right = next->left; // ¶�Lnext�`�I
			}
			else{
				ptr->left=next->left;
			}
			strcpy(ptr->name ,next->name);
            strcpy(ptr->phone,next->phone);// ���N!!
			free(next);	// �R��next (�`�N: ���O�R��ptr)
		}
	}
	return root;	// �^�Ǧ���
}
node *find_node(node *ptr,node input){
	while(ptr != NULL){
		if(strcmp(ptr->name ,input.name)==0){
			return ptr;
		}
		else{
			if(strcmp(ptr->name , input.name)>0){
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
	node *ptr;
	while(1){
		scanf("%c",&op);
		switch(op){
			case 'i':
				scanf("%s",input.name);
                scanf("%s",input.phone);

				root=insert_node(root, input);
//				strcpy(input.phone,NULL);
                break;
			case 'l':
				print_inorder(root);
				break;
			case 'm':
				print_preorder(root);
			//	puts("");
				break;
			case 'n':
				print_postorder(root);
			//	puts("");
				break;
			case 'q':
				return 0;
				break;
			case 'f':
				scanf("%s",input.name);
				ptr=find_node(root,input);
				if(ptr==NULL){
					printf("not found\n");
				}
				else{
					printf("found:\nName: %s\nPhone: %s\n",ptr->name,ptr->phone);
				}
				break;
			case 'd':
				scanf("%s",input.name);
				ptr=delete_node(root,input);
				if(ptr==NULL){
					printf("cannot delete\n");
				}
				else{
					printf("delete %s ok\n\n",input.name);
				}
				break;
		}
	}
	return 0;
}
