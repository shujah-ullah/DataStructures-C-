#include<iostream>
using namespace std;
int sum(int n)
{
	if(n==0)
		return 0;
	else
	return sum(n-1)+n;
}
int ISum(int n)
{
	int i, s = 0;
	for(i=1; i<=n; i++)
		s=s+i;
	return s;
}
int main()
{
	int a;
	//recursive 
	//a = sum(5);
	//iterative
	a = ISum(5);
	cout<<a;
	return 0;
}