#include<iostream>
using namespace std;
struct node{
	float coeff;
	int exponent;
	node* next;
};


node* insert( node* head, float co, int ex)
{
	node* tmp;
	node* newP = new node();
	newP->coeff = co;
	newP->exponent = ex;
	newP->next = NULL;
	
	//if there is no node
	//if exponent part of new node is greater than exponent of first node.
	if( head == NULL || ex > head->exponent)
	{
		newP->next = head;
		head = newP;
	}
	else
	{
	tmp = head;
	//iterate temp over nodes and stop at node whose
	//exponent part is less than ex.
	while( tmp->next != NULL && tmp->next->exponent >= ex)
			tmp = tmp->next;
	newP->next = tmp->next;
	tmp->next = newP;	
	}
	return head;	
}

node* Create(node* head)
{
		int n, i;
		float coefficient;
		int expo;
		cout<<"Enter No of Terms: "<<endl;
		cin>> n;
		for( int i = 0; i<n; i++)
		{
			cout<<"Enter coefficient for term: "<<i+1<<endl;
			cin>>coefficient;
			cout<<"Enter exponent for Term: "<<i+1<<endl;
			cin>>expo;
			head = insert( head , coefficient, expo );	
		}
		return head;
}
void print ( node* head)
{
	if(head == NULL)
		cout<<"No Polynomial: "<<endl;
	else
		{
		node* tmp = head;
		cout<<"Polynomial Entered is: "<<endl;
		while(tmp != NULL)
		{
			cout<<tmp->coeff<<" x^"<<tmp->exponent;
			tmp = tmp->next;
		if(tmp != NULL)
			cout<<" + ";
		else
			cout<<"\n";
		}
}
}
int main()
{
	struct node* head = NULL;
	cout<<"Enter the Polynomials\n: ";
	head = Create(head);
	print(head);
	return 0;
}
