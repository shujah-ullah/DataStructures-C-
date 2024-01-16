//STACK Data Structure with all methods
#include<iostream>
using namespace std;
///Node for linked list
struct Node
{
	int data;
	Node *next;
};
////Stack Methods.
Node *Top = NULL;

void push(int element)
{
	Node *ptr = new Node;
	ptr->data = element;
	ptr->next = Top;
	Top = ptr;
	
	
}
int pop()
{
	int popvalue;
	Node *tmp = Top;
	popvalue = Top->data;
	Top = Top->next;
	free(tmp);
	return popvalue;
}
//int isEmpty();
void printStack()
{
	Node* tmp = Top;
	if(Top == NULL)
	 cout<<"List is empty: "<<endl;
	while(tmp != NULL)   
		{
		
		cout<<tmp->data<<" ";
		tmp = tmp->next; 
	
		}	
}

int main()
		
	
{
		
	push(100);
	push(200);
	push(300);
	pop();
	pop();
	pop();
	printStack();
	




} 

