#include<iostream>
using namespace std;
int main()
{
	//Creating Arrays inside Heap i.e Dynamic Arrays
	int *P;
	P = new int [5];
	P[0] = 12;
	P[1] = 13;
	
	for(int i = 0;i<5; i++)
	{
		cout<<P[i]<<" ";
	}
	cout<<endl;
	delete[] P;	
}