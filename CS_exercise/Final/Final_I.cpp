#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

class node
{
	private:
		int data;
 		node *next;
		friend class LinkedList;
};
class LinkedList
{
	public:
		LinkedList();
		void insert(int value);
		void print();
        void print_rev();
		bool find_or_not(int value);
		bool delete_or_not(int value);
	private:
		node *getnode ();
		void freenode (node *p) ;
		void insert_node (node *ptr, int value);
		void delete_node(node *ptr);
        void print_reverse(node *ptr);
		node *find_node(int num);
		int length ();
		node *head;
};

LinkedList::LinkedList()
{
	head = NULL;
}

node *LinkedList::getnode ()
{
	node *p;
	p = new node;
	if ( p == NULL)
	{
		cout << "?????" << endl;
		exit(1);
	}
	return(p);
}
void LinkedList::freenode (node *p)
{
	delete p;
}

void LinkedList::insert_node ( node *ptr, int value)
{ 
	node *new_node;
	new_node = getnode();
	new_node->data = value;
	new_node->next = NULL;
	
	if ( ptr == NULL )
	{
		
		new_node->next = head;
		head = new_node;
	}
	else
	{
		if ( ptr->next == NULL )

			ptr->next = new_node;
		else
		{
	
			new_node->next = ptr->next;
			ptr->next = new_node;
		}
	}
}

void LinkedList::delete_node(node *ptr)
{
	node *previous;
	if ( ptr == head )
	{
		head = head->next;
	}
	else
	{
		previous = head;
		while ( previous->next != ptr )
			previous = previous->next;
		if ( ptr->next == NULL )
			previous->next = NULL;
		else

			previous->next = ptr->next;
	}
	freenode(ptr);
}
node *LinkedList::find_node(int num)
{
	node *ptr;
	ptr = head;
	while ( ptr != NULL )
	{ 
		if ( ptr->data == num )
		return (ptr);
		ptr = ptr->next;
	} 
	return (ptr);
}
int LinkedList::length ()
{
	int num=0;
	node *q = head;
	while (q != NULL) 
	{
		num ++;
		q = q->next; 
	}
	return(num);
}

void LinkedList::insert(int value)
{
	node *ptr;
	
	ptr = head;
	if(head==NULL)
	{
		insert_node(NULL, value);
	}
	else
	{
		while(ptr->next != NULL)
			ptr = ptr->next;
		insert_node(ptr, value);
	}
}
void LinkedList::print()
{
	node *q = head;
	while (q != NULL) 
	{
		cout << q->data << " ";
		q = q->next; 
	}
	cout << endl;
}
void LinkedList::print_reverse(node *p){
    if(p != NULL){
        print_reverse(p->next);
        cout<<p->data<<" ";
    }
}
void LinkedList::print_rev(){
    node *ptr;
    ptr=head;
    print_reverse(ptr);
    cout<<endl;
}
bool LinkedList::find_or_not(int value){
	node *ptr;
	ptr=find_node(value);
	
	if(ptr != NULL){
		return true;
	}
	else
		return false;
};
bool LinkedList::delete_or_not(int value){
	node *ptr;
	ptr=find_node(value);
	if(ptr != NULL){
		delete_node(ptr);
		return true;
	}
	else
		return false;
};
int main(){
	int N;
	cin>>N;
	LinkedList Number;
    for(int i=1;i<=N;i++){
        if(N%i==0){
            Number.insert(i);
            int counter=0;
            for(int j=1;j<=i;j++){
                if(i%j==0)
                    ++counter;
            }
            if(counter==2)
                cout<<i<<" "<<"P"<<endl;
            else
                cout<<i<<" "<<"N"<<endl;
        }
    }
    char op;
    while(1){
        cout<<"Print In Order : l"<<endl;
        cout<<"Print In Reverse: r"<<endl;
        cout<<"Quit :q"<<endl;
        cin >>op;
        switch(op){
            case 'l':
                Number.print();
                break;
            case 'r':
                Number.print_rev();
                break;
            case 'q':
                return 0;
                break;
        }
        
    }

	
	return 0;
}
