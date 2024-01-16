#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* Next; // pointer of data type class node
		
		//parametrized constructor		
};

void printlist(Node* n)	
		{
			while(n!=NULL){
		
				cout<<n->data<<endl;
				n = n->Next;
			}
		}

int main()
{
	Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();
	
	head->data = 1;
	head->Next = second;
	second->data = 2;
	second->Next = third;
	third->data = 3;
	third->Next = NULL;
	
	
	printlist(head);
	
	
	
	
	
	
	
}