//program to rotate array left
/*Time complexity O(n) Auxiliary space O(n)
			Alternative is JUGGLING Algorithm 
			Time complexity O(n) Auxiliary space O(1)*/			
#include<iostream>
using namespace std;
void rotateleft(int arr[], int size, int d)
{
	int temp[size];
	int k =0;
	for(int i=d; i<size ;i++)
	{
		temp[k] = arr[i];
		k++;
	}
	for(int i =0; i<d; i++)
	{
		temp[k ]= arr[i];
		k++;
		//it stores arr[0] and arra[1] to temp[5] and temp [6]
	}
	for(int i=0; i<size ;i++)
	{
		arr[i] = temp [i];
		//copy rotated array to original array
	}	

}
	void displayarray(int arr[], int n)
	{
		for(int i = 0 ; i<n ; i++)
		{
			cout<<arr[i];
		}
		cout<<endl;
	}

int main()
{
	int array[] = {1,2,3,4,5,6,7,8,9,10};

	int d= 5;
	int n= 10;
	//output should be 3456712 every elemnent rotated left by two indices
	displayarray(array, n);
	rotateleft(array,n,d);
	displayarray(array, n);
	
	
	
}
