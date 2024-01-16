#include<iostream>
using namespace std;
int pow(int m, int n)
{
	if (n == 0)
		return 1;
	return 
		pow(m,n-1)*m;
}
int Power(int m, int n)
{
	if(n == 0 )
	 	return 1;
	//if power is Even.
	if(n %2 == 0) 
		return Power(m*m, n/2);
	//if power is Odd.
	else
		return m*Power(m*m, (n-1)/2);
}
int main()
{
	int result = 0;
	result= Power(10,30);
	cout<<result;
	
}