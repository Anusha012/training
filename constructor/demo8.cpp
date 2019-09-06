#include<iostream>
using namespace std;

class Box
{
	 int width, height;
public:
	Box(int w, int h)//:height(h) , width(w+height)
	{
		height=h;
		width=w+height;
		
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
