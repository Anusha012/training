#include<iostream>
using namespace std;

class Box
{
	const int width = 1, height = 2;
public:
	Box(int width, int height) :width(width), height(height)
	{
		//this->width = 6;
	}

	void disp()
	{
		
		cout << "width=" << width << endl;
		cout << "height=" << height << endl;
	}
};

int main()
{
	Box b(10, 20);
	b.disp();
	return 0;
}
