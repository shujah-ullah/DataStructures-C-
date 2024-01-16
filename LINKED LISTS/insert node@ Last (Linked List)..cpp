#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* link;
};
Node* head;
int main()
{
	Node* firstnode = new Node();
	Node* secondnode = new Node();
	firstnode->link = secondnode;
	
	cout<<"Node is at "<<firstnode<<endl;
	firstnode->data = 1;
	
	secondnode->data = 2;
	secondnode->link = NULL;
	
	head = firstnode;
	cout<<"head: "<<head<<endl;
	
	cout<<"link ptr of first: "<<firstnode->link<<endl;
	cout<<"NOde 2: "<<secondnode<<endl;
	
	
}