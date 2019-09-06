#include<iostream>
using namespace std;

class Arithmetic
{
	int i;
public:
	Arithmetic():i(12)
	{}

	void divide(int d)
	{
		try
		{
			if(d==0)
				throw d;
			else
				i=i/d;
			try
			{
				int *p=NULL;
				if(p==NULL)
					throw "NullPOinterException has occurred";
				else
					cout<<*p<<endl;
			}
			catch(float f)
			{}

		}
		catch(int d)
		{}
		catch(char *s)
		{

			cout<<s<<endl;
		//	throw s;//rethrow
		}
		catch(...)
		{
			cout<<"exception occured in divide"<<endl;
		}


	}
};


void main()
{
	Arithmetic a;
	try
	{
	a.divide(2);
	}
	catch(...)
	{
		cout<<"exception caught in main"<<endl;
	}

	cout<<"in main"<<endl;
}











