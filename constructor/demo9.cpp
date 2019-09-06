#include<iostream>
using namespace std;

class Box
{
	int w, h;
public:
	Box(int width, int height) :h(height)//, w(h + width)
	{
		w = h + width;
	}

	void disp()
	{
		cout << "width=" << w << endl;
		cout << "height=" << h << endl;
	}
};

int main()
{
	Box b(10, 20);
	b.disp();
	return 0;
}

