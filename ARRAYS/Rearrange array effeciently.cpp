// C++ program for rearrange an
// array such that arr[i] = i.
#include <iostream>
using namespace std;
 
int* fixArray(int arr[], int n)
{
 
    int i = 0;
    while (i < n) {
        int correct = arr[i];
        if (arr[i] != -1 && arr[i] != arr[correct]) {
          // if array element should be lesser than
          // size and array element should not be at
          // its correct position then only swap with
          // its correct position or index value
            swap(arr[i], arr[correct]);
        }
        else {
          // if element is at its correct position
          // just increment i and check for remaining
          // array elements
            i++;
        }
    }
    return arr;
}
 
// Driver Code
int main()
{
    int arr[] = { -1, -1, 6, 1, 9, 3, 2, -1, 4, -1 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // Function Call
    fixArray(arr, n);
 
    // Print output
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}