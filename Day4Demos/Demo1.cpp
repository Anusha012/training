#include<iostream>
using namespace std::cout;



class A
{
public:
	void disp()
	{
		cout<<"A::disp"<<endl;
	}
	
	
};

class B :public A
{
public:
	void disp(int a)
	{
		cout<<"B::disp"<<endl;
	}


	using A::disp;
};

void main()
{
   B b1;
   b1.disp();
}*/
void main()
{}