#include<iostream>
using namespace std;

class Demo
{
	int i;
public:
	Demo(int a=1):i(a)
	{}
	void disp()
	{
		cout<<i<<endl;
	}
	void operator++(int s)
	{
		cout<<"op++ ->post increment"<<endl;
		i++;
	}
	void operator++()
	{
		cout<<"op++ ->pre increment"<<endl;
		++i;
	}
	Demo operator+(Demo &d2)
	{
		cout<<"op+"<<endl;
		Demo temp;
		temp.i = this->i + d2.i;
		return temp;
	}

	void operator+(int k)
	{
		cout<<"op+ -> int"<<endl;
		i = i+k;
	}

	void operator=(Demo &temp)
	{
		cout<<"op="<<endl;
		i = temp.i;
	}
	friend void operator+(int k,Demo &d3);
	friend void operator>>(istream &cin , Demo &d3);
	friend ostream& operator<<(ostream &cout , Demo &d3);
	friend void operator=(Demo &d3);
};

void operator+(int k,Demo &d3)
{
	cout<<"op+ ->global"<<endl;
	d3.i = k+d3.i;
}

void operator>>(istream &cin , Demo &d3)
{
	cout<<"op>>"<<endl;
	cout<<"enter an integer"<<endl;
	cin>>d3.i;
}
ostream& operator<<(ostream &cout , Demo &d3)
{
	cout<<"op<<"<<endl;
	cout<<d3.i;
	return cout;
}
void operator=(Demo &d3)
{
		cout<<"op="<<endl;
		i = d3.i;
}
int main()
{
	Demo d1;
	d1++;//d1.operator++(int s)
	++d1;//d1.operator++()
	d1.disp();

	Demo d2(2);
	Demo d3;
	d3= d1+d2;//d3.operator=(temp)
	d3.disp();

	int k=4;
	d3+k;//d3.operator+(k)
	d3.disp();


	k+d3;//operator+(k,d3)
	//d3.disp();
	cin>>d3;//operator>>(cin,d3)
	cout<<d3<<endl;//operator<<(cout,d3);
	

}
/*:: sizeof ?: *.
5^2
pow(5,2)*/
