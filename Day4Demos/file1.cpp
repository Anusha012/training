#include<iostream>
using namespace std;

namespace userstd
{


void disp()
{
	//cout<<i<<endl;
}
class Demo
{
public:
	void disp()
	{
		cout<<"Demo::disp"<<endl;
	}
};
}


void main()
{
	int i=97;
	char i='a';
	//static int i=23;
	//using namespace userstd;
   cout<<i<<endl;
}