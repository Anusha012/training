#include <iostream>
using namespace std;
class myFunctorClass
{
public:
	myFunctorClass(int x) : _x(x) {}
	int operator() (int y) { return _x + y; }
private:
	int _x;
};

int main()
{
	myFunctorClass addFive(5);
	cout << addFive(6);

	return 0;
}
