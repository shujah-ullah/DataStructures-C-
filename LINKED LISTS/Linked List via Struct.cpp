#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* link;
	
};
Node * head = NULL;

int main()
{	
	
	Node* firstnode = new Node();
	Node* secondnode = new Node();
	//First Node
	firstnode->data = 1;
	firstnode->link = secondnode;
	//head points to first node
	head = firstnode;
	//Second Node
	secondnode->data = 2;
	secondnode->link = NULL;
	
	cout <<"firstnode pointing to: "<< firstnode <<endl;
	cout <<"head pointing to: "<< head <<endl;
	cout <<"link of first node pointing to: "<< firstnode->link <<endl;
	cout <<"second node pointing to: "<< secondnode <<endl;
	cout <<"link of second node pointing to: "<< secondnode->link <<endl;
	

	
	
}