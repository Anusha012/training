#include<iostream>
using namespace std;

class Student
{
	int marks;
public:
	Student(int m): marks(m)
	{}

	int getMarks()
	{
		return marks;
	}
};

class Institute
{
	static Institute *in;
	Student *s;
	Institute():s(NULL)
	{cout<<"constr"<<endl;}
public:

  static  Institute* CreateInstance()
	{
		if(in==NULL)
			 in = new Institute();
		return in;
	}

	void RegisterStudent()
	{
		s=new Student(66);
	}

	void disp()
	{
		cout<<s->getMarks()<<endl;
	}
	~Institute()
	{
		delete s;
	}
	static void DeleteInstance()
	{
		if(in!=NULL)
		{
			delete in;
			in=NULL;
		}
	}
};

Institute* Institute::in=NULL;

void main()
{
	Institute *inst=NULL;
	inst=Institute::CreateInstance();
	inst->RegisterStudent();

	Institute *inst2=Institute::CreateInstance();
	inst2->disp();
	Institute::DeleteInstance();
}
