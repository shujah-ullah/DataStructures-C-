#include<iostream>
using namespace std;
//factorial recursively
int fact (int n){
	if(n == 0)
		return 1;
	return (fact(n-1)*n);
}
//factorial Iteratively.
int Ifact(int n)
{
	int a = 1;
	for(int i =1; i<=n; i++)
	{
		a = a*i;
	}
		
	
	return a;
}
int main()
{
	int factorial;
	factorial = Ifact (16);
	cout<<factorial;
}