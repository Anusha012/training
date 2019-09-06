#include<iostream>
using namespace std;

namespace outer
{
	int j=23;
    namespace inner
	{
		int i=34;
	}
}

namespace A
{
	int i=1;
}

namespace A
{
	int j=2;
}

namespace std
{
	int z=45;
}







void main()
{
//using namespace outer::inner;
//using namespace outer;
using namespace A;
	cout<<i<<endl;
	cout<<j<<endl;

	cout<<z<<endl;
	int cout=9;
	std::cout<<cout<<endl;
}

