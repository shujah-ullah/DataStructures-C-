#include<iostream>
using namespace std;
struct Array
{
	int A[20];
	int size;
	int length;	
};
void display(struct Array arr)
{
	cout<<"Elements of arrays are:"<<endl;
	for( int i=0; i<arr.length; i++)
		cout<<arr.A[i]<<endl;
}
void append( struct Array *arr, int x)
{
	if(arr->length < arr->size)
		arr->A[arr->length++] = x; //first it will assign to arr->length then increment b/c operators precedence
}
void Insert (Array *arr, int index, int x)
{
	if(index > 0 && index < arr->length)
	{
		for (int i = arr->length; i>index; i--)
	{
		arr->A[i] = arr->A[i-1];
	}
		arr->A[index] = x;
		arr->length++;
	}
	
}

void Delete(Array *arr ,int index)
{
	if(index > 0 && index < arr->length)
	{
		for(int i = index; i<arr->length; i++)
		{
			arr->A[i] = arr->A[i+1];
		}
		arr->length--;
	}
}

void Search(Array arr, int x)
{
	int F = 0;
	for(int i = 0; i<arr.length; i++)
	{
		if(arr.A[i]==x)
			{
			cout<<"Element Found: "<<endl;
			F=1;
			}
	}
	if(F == 0)
		cout<<"Element Not present: "<<endl;
}
int BinSearch(Array arr, int key)
{
	int l = 0;
	int h = arr.length-1;
	//loop
	
	
	while(l<=h)
	{
		int mid = (l+h)/2;
		if(key == mid)
			return key;
		if(key < arr.A[mid])
			h = mid -1;
		else
			l = mid+1;
	}
	return -1;	
}

int max (int array[], int length)
{
	int max = array[0];
	for(int i = 1; i<length; i++)
	{
		if(array[i]>max)
			max = array[i];
	}
	return max;
}

int min (int array[], int length)
{
	int min = array[0];
	for(int i = 1; i<length; i++)
	{
		if(array[i]<min)
			min = array[i];
	}
	return min;
}

void  Reverse(Array *arr)
{
	//create a new array and copy elements of A in Reverse order
	int * B = new int[arr->length];
	for(int i = arr->length-1, j = 0; i>=0; i--, j++)
		B[j] = arr->A[i];
	//Again copy Reversed array from B to A
	for( int i=0 ; i<arr->length; i++)
		arr->A[i] = B[i];
}

struct Array* Merge(Array *arr1 , Array *arr2)
{
	int i, j, k;
	i=j=k=0;
	
	struct Array *arr3 = new struct Array;
	while(i<arr1->length && j < arr2->length)
	{
		if(arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++];
		else
			arr3->A[k++] = arr2->A[j++];
	}
	//copy remaining elements
	for(; i< arr1->length; i++)
		arr3->A[k++] = arr1->A[i];
	for(; j< arr2->length; j++)
		arr3->A[k++] = arr2->A[j];
	arr3->length = arr1->length + arr2->length;
	arr3->size = 10;
	
	return arr3;
	
}
int main()
{
	struct Array arr = {{2,4,6,8,10},10,5};
	struct Array arr2 = {{1,3,5,7,9},10,5};
	//append(&arr,100);
	display(arr);
	display(arr2);
	//Insert(&arr, 4 ,200);
	//display(arr);
	//Delete(&arr, 4);
	//display(arr);
	//Search(arr, 3);
	//if(BinSearch(arr,30) == -1)
	//	cout<<"element not found: "<<endl;
	//else
	//	cout<<"element found: "<<endl;
	
	//cout<<"maximum element is: "<<max (arr.A, arr.length)<<endl;
	//cout<<"minimum element is: "<<min (arr.A, arr.length)<<endl;
	
	//Reverse(&arr);
	//display(arr);
	struct Array *arr3;
	arr3 = Merge(&arr , &arr2);
	cout<<"After Merging: ";
	display(*arr3);
}