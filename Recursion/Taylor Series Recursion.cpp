#include<iostream>
using namespace std;
double e(int x , int n)
{
	double r;
	static double p=1;
	static double f=1;
	//base condition 
	if(n==0)
		return 1;
	else
	{
		r=e(x, n-1);
		p = p*x;
		f = f*n;
		return r+p/f;
		
	}
}
int main()
{
	cout<<e(4,100);
}