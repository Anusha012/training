#include<iostream>
using namespace std;

void disp(float s)
{
	cout << "float" << endl;
}
void disp(int s)
{
	cout << "int" << endl;
}
void disp(double s)
{
	cout << "double" << endl;
}
void disp(char s)
{
	cout << "char" << endl;
}


int main()
{
	int i = 97;
	disp(i);
	return 0;
}
