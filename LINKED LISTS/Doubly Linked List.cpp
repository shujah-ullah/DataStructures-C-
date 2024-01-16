#include<iostream>
using namespace std;
struct node{
	node *prev;
	int data;
	node *next;
};
node* addToEmpty(node* head, int data)
{
	node* tmp =new node;
	tmp->prev = NULL;
	tmp->data = data;
	tmp->next = NULL;
	head = tmp;
	return head;
}
node* insertAtbeg(node* head, int data){
	node* tmp = new node;
	tmp->prev = NULL;
	tmp->data = data;
	tmp->next = NULL;
	tmp->next = head;
	head->prev = tmp;
	head = tmp;
	return head;
}
node* insertAtEnd(node* head , int data)
{
	node* tmp = new node();
	tmp->data = data;
	tmp->next = NULL;
	tmp->prev = NULL;
	node* tp = head;
	while(tp->next != NULL)
	{
		tp = tp->next;
	}
	tp->next = tmp;
	tmp->prev = tp;
	
	return head;
}
node* InsertAtindex(node* head, int position, int data)
{
	node* ptr= new node();
	ptr->data = data;
	ptr->next = NULL;
	ptr->prev = NULL;
	node* tmp = head;
	while(position != 1)
	{
		tmp = tmp->next;
		position--;
	}
	node* tmp2 = tmp->next;
	tmp->next = ptr;
	ptr->prev = tmp;
	ptr->next = tmp2;
	tmp2->prev = ptr;
	
	return head;
}
node* deletefirst(node* head){
	node* tmp = new node();
	tmp = head;
	head = head->next;
	head->prev = NULL;
	free(tmp);
	return head;
}

node* deleteLast(node* head){
	node* tmp = head;
	node* tmp2 = head;
	while(tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp2 = tmp->prev;
	tmp2->next = NULL;
	free (tmp);
	return head;
}

node* deleteAtindex(node* head , int index){
	node* tmp = head;
	node* tmp2 = head;
	if( index == 1)
	{
		head = deletefirst(head);
		return head;
	}

	int position= index;
	while(position != 1)
	{
		tmp = tmp->next;
		position--;
	}
	if(tmp->next == NULL)
	{
		head = deleteLast(head);
	}
	else{


	tmp2 = tmp->prev;
	tmp2->next = tmp->next;
	tmp->next->prev = tmp2;
	free (tmp);
	tmp = NULL;
	return head;
	}
}
/////////////CORRECTIONS TO BE MADE////////////////
////////////////////////////***************/////////////////////
node* ReverseList(node* head){
	node* tmp = head;
	node* tmp2 =head;
	node* temporary;
	tmp->next = NULL;
	while(tmp->next != NULL)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		temporary = tmp2->prev;
		tmp2->prev = tmp2->next;
		tmp2->next = temporary;
	}
	head = tmp;
	return head;
}
int main()
{
node* head = NULL;
node* ptr;
head = addToEmpty(head, 45);
head = insertAtbeg(head, 50);
head = insertAtbeg(head, 60);
head = insertAtbeg(head, 70);
head = insertAtEnd(head , 100);
head=InsertAtindex(head, 4, 1000);
head = deletefirst(head);
deleteLast(head);
head = deleteAtindex(head , 3);
//head = ReverseList(head);
ptr = head;
while(ptr != NULL)
{
	cout<<ptr->data<<" ";
	ptr= ptr->next;
}
}


















