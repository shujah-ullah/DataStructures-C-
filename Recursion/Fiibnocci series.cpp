//fIBNOCII SERIES 
#include<iostream>
using namespace std;
//Using Iteration
int fibI (int n)
{
	int t0 = 0, t1 =1, s = 0;
	
	if(n<=1)
		return n;
	for(int i = 2; i<=n; i++)
	{
		s = t0+t1;
		t0 = t1;
		t1 = s;
	}
		return s;
}
//using Recursion
int fibR(int n)
{
	if(n<=1)
	return n;
return fibR(n-2)+fibR(n-1);
}
int main()
{
	cout<<"Fibnocci series is: "<<fibR(5)<<endl;
	
}