#include<iostream>
using namespace std;
#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x)
{
	if(rear == N-1)
	{
		cout<<"Queue is Full"<<endl;
	}
	else if(rear == -1 && front == -1)
	{
		front = 0; 
		rear = 0;
		queue[rear] = x;
	}
	else
	{
		rear++;
		queue[rear] = x;
	}
}
void dequeue()
{
	//Under flow condition
	if(front == -1 && rear == -1)
	{
		cout<<"Queue is already empty: "<<endl;
	}
	else if(front == rear)
	{
		front = rear = -1;
	}
	else
	{
		front++;
	}
}
// is Empty
bool isEmpty(int queue[]) {
    if (front == rear && front != 0 && rear != 0){
        return true;
    }
    return false;
}
void display()
{
	if(front == -1 && rear == -1)
	{
		cout<<"Queue is Empty:"<<endl;
	}
	else
		{
			for(int i = front; i<rear+1; i++)
				cout<<queue[i]<<" ";
		}
}
void peek()
{
	if(front == -1 && rear == -1)
	{
		cout<<"Queue is Empty:"<<endl;
	}
	else
		cout<<"front element is: "<<queue[front]<<endl;
}

int main()
{
	enqueue(5);

	if(isEmpty(queue))
	{
		cout<<"queue is empty: ";
	}
	else
	 	cout<<"queue is not empty";
}