#include<iostream>
using namespace std;

class sample
{
public:
	void set()
	{
		cout << "in set" << endl;
	}
	void display()const
	{
		cout << "in display" << endl;
	}
};
int main()
{
	sample s1;
	s1.display();
	const sample s2;
	s2.set();
	return 0;
}
