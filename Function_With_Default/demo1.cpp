#include<iostream>
using namespace std;

void g(int a, int b, int c);
void g(int a, int b, int c = 11);
void g(int a, int b = 22, int c);


//void g(int a, int b= 22, int c= 11);

int main()
{
	g(2);
	return 0;
}

void g(int a, int b, int c)
{
	cout << a << " " << b << " " << c << endl;
}
