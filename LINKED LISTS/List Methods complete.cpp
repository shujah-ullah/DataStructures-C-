#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* link;
};
Node* head = NULL;


/////*INSERT BEGINING*/////.
void insertbeg( int d )
{
	Node *ptr = new Node();
	ptr->data = d;
	ptr->link = head;
	head = ptr;
}

/////*INSERT END.*/////
void insertEnd( int d )
{
	Node* ptr = new Node();
	ptr->data = d;
	ptr->link = NULL;
	
	
//IF list is empty
if ( head == NULL)
head = ptr;
//if list is not empty
else
{
	Node* temp = head;
	while( temp->link != NULL)
	{
		temp = temp->link;
	}
	temp->link = ptr;
}
}

////// insert at given index///
void insertnode(int data, int location)
{
	
	if(head != NULL && location > 1)
	{
	    
	Node *ptr= head;
	Node *prev = head;
	Node* newnode = new Node();
	newnode->data = data;
	
	
	for(int i=1; i<location; i++)
	{
		prev = ptr;
		ptr= ptr->link;
	}
	
	prev->link = newnode;
	newnode->link = ptr;
	}
	if( location == 1 ) 
		{
			Node* newnode = new Node();
			newnode->data = data;
			newnode->link = head;
			head = newnode;
				
		}	
	
	
}

/////*DELETE BEGINING*/////
void deletebeg(){
	//if list is empty
	if(head==NULL)
	cout<<"list is empty\n";
	else
	{
		Node* ptr = head;
		head = head->link;
		free(ptr);
	}
}

/////*DELETE END*/////
void deleteEnd()
   {
		Node *ptr;
		//if list is empty
		if(head==NULL)
		cout<<"list is empty\n";
		//if list has only one element
		if(head->link==NULL)
	{
		ptr = head;
		head = NULL;
		free(ptr);
	}
	else //Traverese list
	{
	Node *prev;
	ptr = head;
	while(ptr->link != NULL){
		prev = ptr;
		ptr = ptr->link;	
	}
	
	prev->link = NULL;
	free(ptr );
}
}

/////*DELETE AT GIVEN DATA*/////
void deletedata(int data)
{
	Node* ptr = head;
	Node* prev = head;
	//corner case
	if(head->data == data)
	{
		head = head->link;
		delete(ptr);
		return;
	}
	while(ptr->data != data)
	{
		prev = ptr;
		ptr = ptr->link;
	}
	prev->link = ptr->link;
	delete(ptr);
}

//////*delete index */////
void deleteindex(int index)
{
	if(head != NULL && index > 1)
	{
	
	Node* ptr = head;
	Node* prev = head;
	for(int i = 1; i<index; i++)
	{
	
		prev = ptr;
		ptr = ptr->link;
	}	
	prev->link = ptr->link;
	delete(ptr);
	
}
//corner case 
		if(index ==1)
		{
			Node* ptr = head;
			head = head->link;
			delete(ptr);
			
		}
}

/////* Mid Node */////
void MidNode()
{
	int a = 0;
	if (head == NULL)
	cout<<"list is empty \n";
	else{
		Node *fast =head;
		Node *slow = head;
		while(fast!= NULL && fast->link != NULL)
		{
			a = a+1;
			fast = fast->link->link; //traverse fast pointer 2 times as of slow pointer
			slow = slow->link;
		}
		cout<<"middle element is: "<<slow->data;
		cout<<"iteration: "<<a<<endl;
	}
}

/////*display linked list*/////
void displaylist()
{	
	Node* temp = head;
	while(temp != NULL)
	{
	
		
		cout<<temp->data;
		
		cout<<" ";
		temp = temp->link;
	}
	cout<<endl;
}

/////////LENGTH OF LIST////////////
int listlen()
{
	Node* ptr = head;
	int count = 0;
	while(ptr != NULL)
	{
		ptr = ptr->link;
		count++;
		
	}
	return count++;
}

///////////get Gth Node//////////////
void GetNode(int index)
{
	
	if (index > listlen() )
	{
		cout<<"Index "<<index<<" Not in Range: "<<endl;
		return;
	}
	Node*ptr = head;
	for(int i=1 ; i<index ; i++)
	{
		ptr = ptr->link;	
	}
	cout<<index<<"th Node is: "<<ptr->data<<endl;
}

/////count occurances of a number in list///
int count(int number)
{
	int counter = 0;
	Node* ptr = head;
	while(ptr != NULL)
	{
		
		if (ptr->data == number)
			counter++;
		
		ptr = ptr->link;
		
	}
	return counter;
}

/////////Length of LOOP in list/////////////
	void lengthofLoop(Node *n)
{
	int length = 1 ;
	Node *tmp = n;
	while(tmp->link != n)
	{
		length++;
		tmp = tmp->link;
	}
	cout<<"length of loop in list is: "<<length<<endl;
	
}
//////detect loop in linked list //////////////
void detectloop()
{
	Node *slow = head;
	Node *fast = head;
	int flag = 0;
	while(slow && fast && fast->link)
	{
		slow = slow->link;
		fast = fast->link->link;
		if (slow == fast )
		{
			flag = 1;
			break;	
		}
	}
	lengthofLoop(slow);
	if(flag == 1)
	{
		cout<<"loop detected: "<<endl;
	}
	else 
		cout<<"No loop exit: "<<endl;
}

int main()
{
	insertEnd(1);
	insertEnd(1);
	insertEnd(3);
	insertEnd(1);
	insertEnd(5);
	insertnode(100,3);
	displaylist();
	cout<<"length of list is: "<<listlen()<<endl;
	GetNode(5);
	cout<<"Number of occurances of 1 in list is: "<<count(1)<<endl;
	//creating loop 
	head->link->link->link->link = head->link;
	
	
	
	detectloop();
	
	


	
}