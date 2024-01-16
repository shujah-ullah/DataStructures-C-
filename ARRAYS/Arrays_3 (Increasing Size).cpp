#include<iostream>
using namespace std;
int main()
{
	int *P = new int[5];
	P[0] = 10;
	P[1] = 20;
	P[2] = 30;
	P[3] = 40;
	P[4] = 50;
	
	int *q = new int[10];
	for( int i = 0; i<5; i++)
	{
		q[i] = P[i];
	}
	
	delete []P;
	P = q;
	q = NULL;

	for(int i =0; i<10; i++)
	{
		cout<<P[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}