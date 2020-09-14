#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

class node
{
    public:
	    int data;
	    node  *left;
	    node *right;
        friend class BST;
};
class BST
{
    public:
       BST();
       void insert(int value);
       void remove(int value);
       //void find(int value);
       void print_in();
       void print_pre();
       void print_post();
       bool find(int value);
    private:
       void insert_node(node *ptr,node input);
       node *find_parent(node *ptr,node input,int *pos);
       void delete_node(node *ptr,node input);
       node *find_node(int value);
       void print_inorder(node *root);
       void print_preorder(node *root);
       void print_postorder(node *root);
       node *head;
};
BST::BST()
{
    head=NULL;
}
void BST::insert_node(node *ptr,node input){
	node *parent;
    node *new_node;
    new_node=(node *)malloc(sizeof(node));
    *new_node=input;
    if(ptr ==NULL){
		head=new_node;
	}	
	else{
		while(ptr!=NULL){
			parent=ptr;
			if(ptr->data > new_node->data){
				ptr = ptr->left;
			}
			else
                ptr=ptr->right;
		}
		if(parent->data >new_node->data){
			parent->left=new_node;
		}
		else{
			parent->right=new_node;
		}
	}
}
void BST::print_inorder(node *ptr){
	if(ptr != NULL){
        print_inorder(ptr->left);
        cout<<ptr->data<<" ";
        print_inorder(ptr->right);
    }

}
void BST::print_preorder(node *ptr){
	if(ptr !=NULL){
		cout<<ptr->data<<" ";
		print_preorder(ptr->left);
		print_preorder(ptr->right);
		
	}
}
void BST::print_postorder(node *ptr){
	if(ptr !=NULL){
		print_postorder(ptr->left);
		print_postorder(ptr->right);
		cout<<ptr->data<<" ";
	}
}
void BST::print_in(){
    print_inorder(head);
}
void BST::print_pre(){
    print_preorder(head);
}
void BST::print_post(){
    print_postorder(head);
}
node *BST::find_parent(node *ptr, node input, int *pos)
{
	node *parent;
	parent = ptr;	// ?qptr?}?l??
	*pos = 0;
	while(ptr != NULL)	
	{
		if(ptr->data== input.data){
            return parent;
        }
        else
        {
            parent=ptr;
            if(ptr->data == input.data)
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
	return NULL;	// ????
}

// ?R???`?I
void BST::delete_node(node *ptr,node input)
{
	node *parent;
	node *current;
	node *next;
	int pos,flag=0;
	parent = find_parent(head, input, &pos);
	if(parent !=NULL)
	{
		switch(pos)	// ?P?_??e?`?I?A???`?I?????k??
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
				head = head->right;
            }
			else				// ??L
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
            delete current;
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
				head = head->left;
            delete current;
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
			delete next;	
		}
    }
    

}
node *BST::find_node(int value){
    node *ptr;
    ptr=head;
	while(ptr != NULL){
		if(ptr->data==value){
            return (ptr);
		}
		else{
			if(ptr->data > value){
				ptr=ptr->left;
			}
			else{
				ptr=ptr->right;
			}
		}
	}
	return (ptr);
}
void BST::insert(int value){
    node *ptr;
    ptr=head;
    node new_node;
    new_node.data=value;
    new_node.left=NULL;
    new_node.right=NULL;
    insert_node(ptr,new_node);
}
void BST::remove(int value){
    node *ptr;
    ptr=head;
    node del_node;
    del_node.data=value;
    delete_node(ptr,del_node);
}
bool BST::find(int value){
    if(find_node(value) != NULL)
        return true;
    else
        return false;
}

int main(int argc, char *argv[]){
	int N,K,M;
    cin >>N;
    BST *btree;
    btree=new BST[N];
    for(int i=0;i<N;i++){
        int value=0;
        cin >>value;
        while(value != -1){
            btree[i].insert(value);
            cin>>value;
        }
    }
    cout<<"In-order:\n";
    for(int i=0;i<N;i++){
        btree[i].print_in();
        cout<<"\n";
    }
    cout<<"Pre-order:\n";
    for(int i=0;i<N;i++){
        btree[i].print_pre();
        cout<<"\n";
    }
    cout<<"Post-order:\n";
    for(int i=0;i<N;i++){
        btree[i].print_post();
        cout<<"\n";
    }

    cin >>K;
    cout<<"Delete "<<K<<"\n";
    for(int i=0;i<N;i++){
        btree[i].remove(K);
        btree[i].print_in();
        cout<<"\n";
    }
    cin>> M;
    cout<<"Find "<<M<<endl;
    for(int i=0;i<N;i++){
        if(btree[i].find(M)){
           cout<<"Yes\n";
        }
        else
            cout<<"No\n";
    }
   
	return 0;
}
