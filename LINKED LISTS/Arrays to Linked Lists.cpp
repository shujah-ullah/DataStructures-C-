#include<iostream>
using namespace std;
int main()
{
	int x [4] = {1,2,3,4};
	x [4] = 0;
	x [5] = 100;
	x [6] = 150;
	x [7] = 200;
	for (int i=0; i<25 ;i++)
	{
		cout<<x[i]<<endl;
	}
	cout<<sizeof(x);
}