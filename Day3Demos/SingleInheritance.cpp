#include<iostream>
using namespace std;
class MOI
{

	static int age;
public:

	MOI(int a)
	{
		cout<<"MOI::constr"<<endl;
	}
	virtual ~MOI()
	{
		cout<<"MOI::destr"<<endl;
	}

	 void display(){
	cout<<age;////overridden method
}
	//virtual void display()=0;//pure virtual methods
};
int MOI::age;

class Faculty :public MOI
{
	int sal;
public:
	Faculty(int a, int s):sal(s),MOI(a)
	{
		cout<<"Faculty::constr"<<endl;
	}
	~Faculty()
	{
		cout<<"Faculty::destr"<<endl;
	}

	void display()//overriding method
	{
		//cout<<"age:"<<age<<endl;
		cout<<"sal:"<<sal<<endl;
		MOI::display();
	}

	

};

int main()
{
	/*
	Faculty f(23,23000);
	f.display();*/

	MOI *p = new Faculty(23,23000);
	p->display();
	delete p;

	return 0;
	
}

/*
class A
{
	int i=1;
	virtual void set(){}
	virtual void get(){}
	void modify(){}
}

class B : public A
{
	int j=2;
	void set(){}
	virtual void update(){}
}

B b1;
*/
