#include<iostream>
using namespace std;
class Queue
{
	private:
		int front;
		int rear;
		int size;
		int* Q;
	public:
		Queue(int size);
		~Queue();
		void enqueue(int x);
		int dequeue();
		void display();
		bool isEmpty();
		bool isFull();
};
Queue::Queue(int size)
{
	this->size = size;
	front = -1;
	rear = -1;
	Q = new int[size];
}
Queue::~Queue()
{
	delete [] Q;
}
bool Queue::isEmpty()
{
	if(front == rear)
		{
			return true;
		}
		return false;
}
bool Queue::isFull()
{
	if(rear == size-1){
		return true;
	}
	return false;
}
void Queue::enqueue(int x)
{
	if(isFull())
	{
		cout<<"Queue Overflow: "<<endl;
	}
	else
		{
			rear++;
			Q[rear] = x;
		}
}
int Queue::dequeue()
{
	int x = -1;
	if(isEmpty())
	{
		cout<<"Queue Underflow: "<<endl;
	}
	else
		{
			front++;
			x = Q[front];
		}
		return x;
}
void Queue::display()
{
	if(front == -1 && rear == -1)
		cout<<"Queue is Empty: "<<endl;
	else
	 	for(int i = front+1; i<=rear; i++)
	 	{
	 		cout<<Q[i]<<" ";
		 }cout<<endl;
}

int main()
{
	int A[] = {10,20,30,40,50};
	Queue q(sizeof(A)/sizeof(A[0]));
	//Queue
	for(int i =0; i < (sizeof(A)/sizeof(A[0])); i++)
	{
		q.enqueue(A[i]);
	}
	//display
	q.display();
	
	//overflow
	q.enqueue(100);
	
	// Dequeue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.dequeue();
    }
	
	 // Underflow
    q.dequeue();
    
    return 0;
	
}