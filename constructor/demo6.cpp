#include<iostream>
using namespace std;

class StringDemo
{
	char *str;
public:
	StringDemo() :str(new char[6])
	{
		strcpy_s(str,6 ,"hello");
	}

	explicit StringDemo(char *s) :str(new char[strlen(s) + 1])
	{
		strcpy_s(str, strlen(s) + 1, s);
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
	StringDemo s3 =s2;
	s3.disp();
	return 0;
}
