#include<iostream>
using namespace std;
int main()
{
	int x [20] = {1,2,3,4,5,6};
	cout<<x[1]<<endl;
	
	x[1] = 10;
	// x = 10; x as an Array is not an L-value 
	
	int *y = new int [20];
	y = x;		// y as an pointer to array is L-value.
	cout<<y[4];
}