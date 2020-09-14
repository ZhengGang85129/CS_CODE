#include <stdlib.h>
#include <string.h>
#include <iostream>
int N=0;
using namespace std;
class node
{
    public:
	    char data[128]; //name;
        char data1[128];//phone;
        int data2;//number;
	    node  *left;
	    node *right;
        friend class BST;
};
class BST
{
    public:
       BST();
       void insert(char name[128],char phone[128]);
       void remove(int value);
       void remove(char name[128]);
       void print_in();
       void print_pre();
       void print_post();
       void find(char name[128]);
    private:
       void insert_node(node input);
       node *find_parent(node *ptr,node input,int *pos);
       void delete_node(node input);
       node *find_node(char name[128]);
       void print_inorder(node *root);
       void print_preorder(node *root);
       void print_postorder(node *root);
       void find_name(int value,int *flag);
       node *head;
       node *get_ptr;
};
BST::BST()
{
    head=NULL;
}
void BST::insert_node(node input){
	node *parent;
    node *new_node;
    new_node=(node *)malloc(sizeof(node));
    *new_node=input;
    N=N+1;
    new_node->data2=N;
    node *ptr;
    ptr=head;
    if(ptr ==NULL){
		head=new_node;
	}	
	else{
		while(ptr!=NULL){
			parent=ptr;
			if(strcmp(ptr->data , new_node->data)>0){
				ptr = ptr->left;
			}
			else
                ptr=ptr->right;
		}
		if(strcmp(parent->data ,new_node->data)>0){
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
        cout<<"Name: "<<ptr->data<<" "<<endl;
        cout<<"Phone: "<<ptr->data1<<" "<<endl;
        cout<<endl;
        print_inorder(ptr->right);
    }

}
void BST::print_preorder(node *ptr){
	if(ptr !=NULL){
        cout<<"Name: "<<ptr->data<<" "<<endl;
        cout<<"Phone:"<<ptr->data1<<" "<<endl;
		cout<<endl;
		print_preorder(ptr->left);
		print_preorder(ptr->right);
		
	}
}
void BST::print_postorder(node *ptr){
	if(ptr !=NULL){
		print_postorder(ptr->left);
		print_postorder(ptr->right);
		cout<<"Name: "<<ptr->data<<" "<<endl;
		cout<<"Phone: "<<ptr->data1<<" "<<endl;
        cout<<endl;
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
		if(strcmp(ptr->data ,input.data)==0){
            return parent;
        }
        else
        {
            parent=ptr;
            if(strcmp(ptr->data ,input.data)>0)
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
void BST::delete_node(node input)
{
	node *parent;
	node *current;
	node *next;
	int pos=0;
	parent = find_parent(head, input, &pos);
	if(parent !=NULL)
	{
		switch(pos)	
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
			if(parent==current)
				head = head->right;
			else				// ??L
			{
				if( pos == 1 )
					parent->right = current->right;
				else	
					parent->left = current->right;
				
			}
            delete current;
		}
		else if(current->right == NULL)	
		{
			if(parent != current)
			{
				if( pos == 1 )
					parent->right = current->left;
				else
					parent->left = current->left;
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
			strcpy(parent->data,next->data);
			strcpy(parent->data1,next->data1);
            parent->data2=next->data2;
            delete next;
		}
    }
}
void BST::remove(char name[128]){
    node input,*ptr;
    ptr=find_node(name);
    if( ptr== NULL){
        cout<<"Cannot Delete!"<<endl;
        cout<<"(1)Out of range or (2) Not in your Friend-List!"<<endl;
    }
    else{
        strcpy(input.data,find_node(name)->data);
        cout<<"Delete :"<<input.data<<endl;
        delete_node(input);

    }
       
}
node *BST::find_node(char name[128]){
    node *ptr;
    ptr=head;
	while(ptr != NULL){
		if(strcmp(ptr->data,name)==0){
            return (ptr);
		}
		else{
			if(strcmp(ptr->data ,name)>0){
				ptr=ptr->left;
			}
			else{
				ptr=ptr->right;
			}
		}
	}
	return (ptr);
}
void BST::insert(char name[128],char phone[128]){
    node *ptr;
    ptr=head;
    node new_node;
    strcpy(new_node.data,name);
    strcpy(new_node.data1,phone);
    new_node.left=NULL;
    new_node.right=NULL;
    insert_node(new_node);

}
void BST::remove(int value){
    node input;
    int flag=0;
    get_ptr=head;
    find_name(value,&flag);
    if(flag == 1){
        strcpy(input.data,get_ptr->data);
        delete_node(input);
        cout<<"Delete :"<<input.data<<endl;
        cout<<endl;
    }
    else if(flag ==2){
        cout<<"Cannot Delete!"<<endl;
        cout<<"(1)Out of Range or (2) Not in your Friend-List!"<<endl;
    }
    else if(flag ==3){
         cout<<"Cannot Delete!"<<endl;
         cout<<"You don't have any friend ..."<<endl;
    }
}
void BST::find_name(int value,int *flag){
        if(get_ptr != NULL){
            if(get_ptr->data2 != value){
                node *tmp;
                tmp=get_ptr;
                *flag=2;
                if(*flag !=1 && *flag !=3){
                    get_ptr=get_ptr->left;
                    find_name(value,flag);
                }
                if(*flag !=1 && *flag !=3){
                    get_ptr=tmp;
                    get_ptr=get_ptr->right;
                    find_name(value,flag);
                }
                if(*flag !=1 && *flag !=3){
                    *flag=2;
                }
            }
            else{
                *flag=1;
            }
        }
        else if(*flag ==0 && get_ptr ==NULL){
            *flag=3;
        }
}
void BST::find(char name[128]){
    if(find_node(name) != NULL){
        cout<<find_node(name)->data2<<":"<<endl;
        cout<<"Name: "<<find_node(name)->data<<endl;
        cout<<"Phone: "<<find_node(name)->data1<<endl;
        cout<<endl;
    }
    else{
        cout<<"Not found"<<endl;
        cout<<endl;

    }

}
int main(int argc, char *argv[]){
    BST root;
    char op;
    char name[128],phone[128];
    int number;
    while(1){
        cout<<"(1)Add Friend's Info: i"<<endl;
        cout<<"(2)List All Friends' Info: l"<<endl;
        cout<<"(3)Find Friend's Info: f'"<<endl;
        cout<<"(4)Delete Friend's Info: r'"<<endl;
        cout<<"(5)Delete Friend's Info: d'"<<endl;
        cout<<"(6)Quit: q"<<endl;
        cin>>op;
        switch(op){
            case 'i':
                cout<<"Name: ";
                cin>>name;
                cout<<"Phone: ";
                cin>>phone;
                cout<<endl;
                root.insert(name,phone);
                break;
            case 'l':
                cout<<"Print Preorder:"<<endl;
                cout<<endl;
                root.print_pre();
                cout<<"Print Inorder:"<<endl;
                cout<<endl;
                root.print_in();
                cout<<"Print Postorder:"<<endl;
                cout<<endl;
                root.print_post();
                cout<<endl;
                break;
            case 'f':
                cout<<"Name: "<<endl;
                cin>>name;
                cout<<endl;
                root.find(name);
                break;
            case 'r':
                cout<<"Serial Number: ";
                cin>>number;
                root.remove(number);
                cout<<endl;
                break;
            case 'q':
                return 0;
                break;
            case 'd':
                cout<<"Name: ";
                cin>>name;
                root.remove(name);
                cout<<endl;
                break;
        }

    }
	return 0;
}
