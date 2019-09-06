#include<iostream>
using namespace std;

class Box
{
	int width, height;
public:
	Box(int w, int h) :width(w), height(h)
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
