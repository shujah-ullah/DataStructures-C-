#include<iostream>
using namespace std;
struct node{
	node *prev;
	int data;
	node *next;
};
node* addToEmpty(node* tail, int data)
{
	node* tmp =new node;
	tmp->prev = tmp;
	tmp->data = data;
	tmp->next = tmp;
	tail = tmp;
	return tail;
}
node* addAtbeg(node* tail , int data){
	node* newP = addToEmpty(tail, data);
	if(tail == NULL)
		return newP;
	else{
		node* temp = tail->next;
	
	newP->prev = tail;
	newP->next = temp;
	temp->prev = newP;
	tail->next = newP;
	return tail;
	
	}
}
/////////O(1)/////////////
node* addAtEnd(node* tail, int data){
	node* newP = addToEmpty(tail, data);
	if(tail == NULL)
		return newP;
	else
	{
	node* tmp = tail->next;
	newP->next = tmp;
	newP->prev = tail;
	tail->next = newP;
	tmp->prev = newP;
	tail = newP;
	return newP;
	}
	
}
////////////O(N)////////
node* addAfterposition(node* tail, int position, int data)
{
	node* newP = addToEmpty(tail, data);
	if(tail == NULL)
		return newP;
	node* tmp = tail->next;
	while(position > 1)
	{
		tmp = tmp->next;
		position--;
	}
	newP->prev = tmp;
	newP->next = tmp->next;
	tmp->next->prev = newP;
	tmp->next = newP;
	if(tmp == tail)
		tail = tail->next;
	
	return tail;
}

node* deletefirst(node* tail)
{
	if( tail == NULL)
		 return tail;
	
	node* tmp = tail->next;
	if(tmp == tail)
	{
		free(tail);
		tail = NULL;
		return tail;
	}
	tail->next = tmp->next;
	tmp->next->prev = tail;
	free(tmp);
	tmp = NULL;
	return(tail);
}

node* deleteLast(node* tail)
{
	node* tmp;
	if( tail == NULL)
		 return tail;
	if(tmp == tail)
	{
		free(tail);
		tail = NULL;
		return tail;
	}
	tmp = tail->prev;
	tmp->next = tail->next;
	tail->next->prev = tmp;
	free(tail);
	tail = tmp;
	return tail;
}

node* deleteNode(node* tail, int position)
{
	node* tmp = tail->next;
	while(position > 1)
	{
		tmp = tmp->next;
		position--;
	}
	node* tmp2 = tmp->prev;
	tmp2->next = tmp->next;
	tmp->next->prev = tmp2;
	
	if(tmp == tail)
		tail = tmp2;
	free(tmp);
	tmp = NULL;
	return tail;
}
void print(node* tail){
		if(tail == NULL)
		{
			cout<<"No node in the list: "<<endl;
		}
		else{
			node* ptr = tail->next;
	do
	{	
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	while(ptr != tail->next);
	cout<<endl;
	}
}
int main()
{
	node* tail = NULL;
	tail= addToEmpty(tail, 0);
	tail = addAtbeg(tail , 1);
	tail = addAtbeg(tail , 2);
	tail = addAtEnd( tail, 3);
	tail = addAfterposition(tail, 2,100); 
	print(tail);
	cout<<"after delete first: " <<endl;
	tail = deletefirst(tail);
	print(tail);
	
	cout<<"after delete Last: " <<endl;
	tail = deleteLast(tail);
	print(tail);
	
	cout<<"delete  node 2: " <<endl;
	tail = deleteNode(tail, 2);
	print(tail);
	
}