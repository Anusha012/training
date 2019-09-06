#include<iostream>
using namespace std;

class Demo
{
	 static int i;//static const int i;
public:
	 void disp()const
	{
		i++;
		cout<<i<<endl;
	}

};

int Demo::i=12;

void main()
{
	//Demo::disp();
	Demo d;
	d.disp();
}






















