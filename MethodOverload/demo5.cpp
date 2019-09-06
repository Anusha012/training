#include<iostream>
using namespace std;


void disp(double s)
{
	cout << "double" << endl;
}

void disp(float a, ...)
{
	cout << "..." << endl;
}


int main()
{
	int i = 97;
	disp(i);
	return 0;
}
