#include<iostream>
using namespace std;


void disp(int s)
{
	cout << "int" << endl;
}

void disp(char s)
{
	cout << "char" << endl;
}


int main()
{
	int i = 97;
	disp((char)i);
	return 0;
}
