#include<iostream>
using namespace std;

class Box
{
	int width, height;
public:
	Box() :width(1), height(2)
	{
	}
	Box(int width = 11, int height = 12) :width(width), height(height)
	{

	}
	void disp()
	{
		cout << "width=" << width << endl;
		cout << "height=" << height << endl;
	}
};

int main()
{
	Box b1;
	b1.disp();
	Box b2(10, 20);
	b2.disp();
	return 0;
}
