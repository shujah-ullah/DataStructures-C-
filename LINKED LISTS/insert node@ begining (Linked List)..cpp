#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* link;
};
Node* head = NULL;
int main()
{
	Node* firstnode = new Node();
	Node* newnode = new Node();
	firstnode->data = 1;
	firstnode->link = NULL;
	
	newnode->data = 2;
	newnode->link =firstnode;
	
	head = newnode;
	cout<<"first node at: "<< firstnode <<endl;
	cout<<"new node at: "<< newnode <<endl;
	cout<<"head at: "<<head<<endl;
	cout<<"link ptr of newnode: "<<newnode->link<<endl;

	
	
	
	
	
	
	
	
	
}