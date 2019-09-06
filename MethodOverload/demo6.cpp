#include<iostream>
using namespace std;


void disp(int s)
{
	cout << "int" << endl;
}

void disp(int a = 23, ...)
{
	cout << "..." << endl;
}


int main()
{
	int i = 97;
	disp(i);
	return 0;
}
