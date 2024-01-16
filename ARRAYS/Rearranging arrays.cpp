/*Rearrange an array such that arr[i] = i*/
/*Time Complexity: O(n2)
Auxiliary Space: O(1), since no extra space has been taken.*/
#include <iostream>
using namespace std; 
void arrange(int arr[], int size)
{
	int i, j, temp;
	for(int i=0; i<size; i++)
	{
			for(int j=0; j<size; j++)
	{
		if(arr[j] == i)
		{
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
			break;
		}
	}
	}
	//if a number isnot present
	for(int i =0; i<size; i++)
	{
		if(arr[i]!=i)
		{
			arr[i] = -1;
		}
	}
	//print array
	cout<<"after rearranging array  ";
		for(int i =0; i<size; i++)
		{
			cout<<arr[i]<<" ";
		}
	
}
int main()
{
	int array[] = {2,3,5,7,10,9,5,-1,0,-1,-1};
	int size = sizeof(array)/sizeof(array[0]);
	arrange(array, size);
	
	
}
