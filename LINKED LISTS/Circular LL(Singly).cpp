#include<iostream>
using namespace std;
struct node{
	int data;
	node* next;
};
node* AddToEmpty(int data){
	node* tmp = new node();
	tmp->data = data;
	tmp->next = tmp; ////pointer of node pointing itself
	return tmp;
}
node* Addbeg(node* tail, int data){
	node* newP = new node();
	newP->data = data;
	newP->next = tail->next;
	tail->next = newP;
	return tail;
}
node* AddatEnd(node* tail, int data){
	node* newP = new node();
	newP->data = data;
	newP->next = tail->next;
	tail->next = newP;
	tail = newP;
	return tail;
}
node* AddAfterPosition(node* tail, int data, int position){
	node *p = tail->next;
	node* newP = new node();
	newP->data = data;
	while(position > 1)
	{
		p = p->next;
		position--;
	}
	newP->next = p->next;
	p->next = newP;
	if(p == tail)
	{
		tail = newP;
	}
	
	return tail;
}

node* CreateList(node* tail){
	int i, n, data;
	cout << "Enter the No of Nodes of linked List: "<<endl;
	cin >> n;
	if( n== 0 )
			return tail;
	cout<<"Enter element 1: "<<endl;
	cin>>data;
	tail = AddToEmpty(data);
	
	for(i = 1; i<n; i++)
	{
		cout<<"Enter the element "<<i+1<<endl;
		cin>>data;
		tail = AddatEnd(tail, data);
	}
	return tail;
}
/////// O(1) ///////////
node* deleteBeg(node* tail){
	node* tmp = tail->next;
	tail->next = tmp->next;
	free(tmp);
	tmp = NULL; 
	return tail;
}
node* deleteLast(node* tail){
	if(tail == NULL)
		return tail;
	node* temp=tail->next;
	if(tail->next == tail)
	{
		free(tail);
		tail = NULL;
		return tail;	
	} 
	while(temp->next != tail)
	{
		temp = temp->next;
	}
	temp->next = tail->next;
	free(tail);
	tail = temp;
	return tail;
}

node* deleteAtposition(node* tail, int position){
	if(tail == NULL)
		return tail;
	node* temp=tail->next;
	if(tail->next == tail)
	{
		free(tail);
		tail = NULL;
		return tail;	
	} 
	node* tmp = tail->next;
	while(position > 2)
	{
		tmp = tmp->next;
		position--;
	}
	node* tmp2 = tmp->next;
	tmp->next = tmp2->next;
	if(tmp2 == tail) // if node to be deleted is the last node.
		tail = tmp2;
	free(tmp2);
	tmp2 = NULL; 
	return tail;
}
void CountNodes(node* tail){
	int count = 0;
	node* ptr = tail->next;
	while(ptr != tail)
	{
		ptr = ptr->next;
		count++;
	}
	count++;
	cout<<"Number of nodes in List is: "<<count<<endl;
}

int search(node* tail,int data ){
	node* tmp = tail->next;
	int index = 0;
	if(tail == NULL)
		return -2;
	do
	{
		if(tmp->data == data)
		return index;
		tmp = tmp->next;
		index++;
	}
	while( tmp != tail->next); //while temp is not equal to first node.
	//if data is not present in the list
	return -1;
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
	tail = CreateList(tail);
	cout<<"List before Deletion is: "<<endl;
	print(tail);
	tail = deleteAtposition(tail, 1);
	cout<<"List after deletion is: "<<endl;
	print(tail);
	CountNodes(tail);
	int element;
	cout<<"search for element: "<<endl;
	cin>>element;
	int index = search(tail, element );
	if(index == -1)
		cout<<"element not found:" <<endl;
	if(index == -2)
		cout<<"list is empty: "<<endl;
	else
		cout<<"element " <<element<<" is at "<<index<<endl;
	return 0;
	

}