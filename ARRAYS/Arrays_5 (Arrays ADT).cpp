#include<iostream>
using namespace std;
struct Array
{
	int *A;
	int size;
	int length;	
};
void display(struct Array arr)
{
	cout<<"Elements are:"<<endl;
	for( int i=0; i<arr.length; i++)
		cout<<arr.A[i]<<endl;
}
int main()
{
	struct Array arr;
	int n;
	cout<<"Enter size of Array: "<<endl;
	cin>>n;
	arr.size = n;
	arr.A = new int[arr.size];
	arr.length = 0;
	cout<<"Enter Array elements: "<<endl;
	for( int i  = 0; i<n; i++)
		cin>>arr.A[i];
	arr.length = n;
	display(arr);
	
	
		
}