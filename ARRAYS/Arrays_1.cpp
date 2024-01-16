#include<iostream>
using namespace std;
int main()
{	
	//method 1
	int A[5] = {2,4};
	
	int size = sizeof(A)/4;
	for (int i =0 ; i< size ;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	//method 2
	int B[] = {2,4,6,0,100};
		for (int i =0 ; i< 5 ;i++)
	{
		cout<<B[i]<<" ";
	}
	cout<<endl;
	// access method 2
	cout<<2[B]<<endl;
	//access method 3 Pointer Arithematic.
	cout<<*(B+2)<<endl;

}