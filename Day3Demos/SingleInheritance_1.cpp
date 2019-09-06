#include<iostream>
using namespace std;
d
class MOI
{
protected:
	int age;
public:

	MOI(int a):age(a)
	{
	
	}
	virtual ~MOI()
	{
	
	}

    int getAge()
	{
		return age;
	}
	
};


class Faculty :public MOI
{
	int sal;
public:
	Faculty(int a, int s):sal(s),MOI(a)
	{
	
	}
	~Faculty()
	{
	
	}

	int getSal()
	{
		return sal;
	}
virtual int getMarks()
{
	return 0;
}
	

};

class Student :public MOI
{
	int marks;
public:
	Student(int a, int m):marks(m),MOI(a)
	{
		
	}
	~Student()
	{
		
	}

	int getMarks()
	{
		return marks;
	}

	

};

class Institute
{
	MOI *m;
public:
	void RegisterMOI()
	{
		cout<<"1:Faculty 2:Student"<<endl;
		cout<<"enter the choice"<<endl;
		int choice=0;
		cin>>choice;
		switch(choice)
		{
		case 1:
			m=new Faculty(23,23000);
			break;
		case 2:
			m=new Student(20,88);
			break;
		}
	}

	void display()
	{
		//if(strcmp(typeid(*m).name(),"class Faculty")==0)
		if(typeid(*m)==typeid(Faculty))
			cout<<m->getAge()<<" "<<((Faculty*)m)->getSal()<<endl;
		else if(typeid(*m)==typeid(Student))
			cout<<m->getAge()<<" "<<((Student*)m)->getMarks()<<endl;
	}
	~Institute()
	{
		if(m)
			delete m;
	}
};



int main()
{
	
/*
	int i=23;
	cout<<typeid(i).name()<<endl;*/

	Institute inst;
	inst.RegisterMOI();
	inst.display();
	return 0;
}

