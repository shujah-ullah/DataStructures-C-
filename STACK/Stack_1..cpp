#include<iostream>
using namespace std;
#define SIZE 5
int Stack[SIZE];
int top = -1;
void push(int a)
{
	//check for overflow
	if(top == SIZE-1)
		cout<<"stack is Full: "<<endl;
	else
		top++;
		Stack[top] = a;
}
void pop()
{
	//check for under flow
	if(top == -1)
		cout<<"Stack is empty";
	else
		top--;
}
void Top()
{
	cout<<"Top element is: "<<Stack[top]<<endl;
}
void display()
{
	for (int i= top; i>=0; i--)
	{
		cout<<Stack[i];
	}
	cout<<endl;
}
int main()
{
	push(3);
	push(4);
	push(5);
	push(6);
	pop();
	Top();
	display();
}