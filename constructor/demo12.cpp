#include<iostream>
using namespace std;
#include<stdio.h>

class Box
{
	int width, height;
public:
	Box() :width(1), height(2)
	{
	}
	Box(int width , int height) :width(width), height(height)
	{
	}
	 Box(const Box &b) :width(b.width), height(b.height)
	{
	}
	void disp()
	{
		cout << "width=" << width << endl;
		cout << "height=" << height << endl;
	}
	Box& modify()
	{
		 Box temp;
		return temp;
	}
};

int main()
{
	Box b1;
//	b1.disp();
	Box b2(10, 20);
//	b2.disp();
	Box b3(b2);
//	b3.disp();

	Box b4 = b3.modify();
	b4.disp();
	return 0;
}
