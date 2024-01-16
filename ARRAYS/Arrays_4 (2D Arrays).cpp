#include<iostream>
using namespace std;
int main()
{
	//Create 2D Array inside Stack
	int A[3][4] = {{2,4,5,6},{20,20,30,40},{0,1,2,3}};
	
	//Partially in HEAP
	int *B[3]; //Array of Pointers in STACK.
	B[0] = new int[4]; //Pointing to Allocated Array in Heap
	B[1] = new int[4];
	B[2] = new int[4];
	B[2][3] = 15;
	cout<<B[2][3]<<endl;
	
	//Completely in HEAP using Double Pointer.
	int **C;
	C = new int* [3]; // POinters to Pointers, STACK pointing to HEAP POinters.
	C[0] = new int[4];
	C[1] = new int[4];
	C[2] = new int[4];
	
	//Accessing Array elements 
	for(int i=0; i<3; i++)
	{
		for(int j=0 ; j<4; j++)
		{
			cout<<C[i][j]<<" ";
		}
	}
	cout<<endl;
	return 0;
}