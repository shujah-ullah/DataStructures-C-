#include<iostream>
using  namespace std;
//Insert in Heap
void Insert(int A[], int n)
{
	int temp, i = n;
	while(i>1 && temp > A[i>2])
	{
		A[i] = A[i/2];
		i= i/2;
	}
	A[i] = temp;
}

void CreateHeap()
{
	int A[] = {0,10,20,30,25,5,40};
	
	for(int i=2; i<6; i++)
		Insert(A, i);	
}
int main()
{
	CreateHeap();
	cout<<A[1];
	
}