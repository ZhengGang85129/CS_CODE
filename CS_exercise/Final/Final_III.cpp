#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;
class node 
{   
    public:
	    int data;
	    node  *next;
};
class Stack{
    public:
        Stack();
        void push(int value);
        int pop();
        void printStack();
    private:
        void printAllNode(node *s);
        node *stack;
        
};

Stack::Stack()
{
          stack=NULL;
}
void Stack::push(int value)
{
	node *new_node;
	
	new_node = (node *)malloc(sizeof(node));
	
    if(!new_node){
	    cout<<"Memory is Filled!"<<endl;
		exit(0);
    }
	new_node->data = value;
	new_node->next = stack;
	stack = new_node;
}
int Stack::pop()
{
	node *top;
	int temp;
	if( stack != NULL )
	{
		top = stack;
		stack = stack->next;
		temp = top->data;
		free(top);
		return temp;
	}
	else 
		return -1;
}

void Stack::printAllNode(node *s)
{
	if(s == NULL)
	{
		return;
	}
	else
	{
		printf("%2d ",  s->data);
		printAllNode(s->next);
	}
}

void Stack::printStack()
{
	printAllNode(stack);
	printf("\n");
}
Stack TowerA, TowerB,TowerC;
void Algorithm(Stack *A,Stack *B, Stack *C, int n,char a,char b,char c){
    if(n==0)
        return;
    Algorithm( A, C, B,n-1,a,c,b);
    int i=0;
    while(i!=n-1){
        A->pop();
        C->pop();
        i=i+1;
    }
    C->pop();
    C->push(A->pop());
    i=0;
    while(i!=n-1){
        C->push(0);
        A->push(0);
        i=i+1;
    }
    A->push(0);
    cout<<"Disk "<<n<<" moves from "<<a<<" -> "<<c<<endl;
    cout<<"Tower A: ";
    TowerA.printStack();
    cout<<"Tower B: ";
    TowerB.printStack();
    cout<<"Tower C: ";
    TowerC.printStack();
    cout<<endl;
    
    Algorithm(B,A,C,n-1,b,a,c);
}
int main()
{
    int N;
    cin >>N;
    for(int i=1;i<=N;i++){
        TowerA.push(N+1-i);
        TowerB.push(0);
        TowerC.push(0);
    }
    cout<<"Initial Condition:"<<endl;
    cout<<"Tower A: ";
    TowerA.printStack();
    cout<<"Tower B: ";
    TowerB.printStack();
    cout<<"Tower C: ";
    TowerC.printStack();
    Algorithm(&TowerA,&TowerB,&TowerC,N,'A','B','C');
	return 0;
}
