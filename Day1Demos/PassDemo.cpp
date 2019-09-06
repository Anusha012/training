#include<iostream>
using namespace std;
void disp(int &i)
{
	cout<<&i<<endl;
	i++;
}

void main()
{
	int j=23;
	cout<<&j<<endl;
	disp(j);
	cout<<j<<endl;
}