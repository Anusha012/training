#include<iostream>
using namespace std;

class StringDemo
{
	char *str; 
public:
	StringDemo() :str("hello")
	{}

	StringDemo(char *s) :str(new char[strlen(s) + 1])
	{
		strcpy(str, s);
	}

	~StringDemo()
	{
		delete[] str;
	}
	void disp()
	{
		cout << str << endl;
	}

};

int main()
{
	StringDemo s1;
	s1.disp();
	StringDemo s2("helloWorld");
	s2.disp();
	return 0;
}
