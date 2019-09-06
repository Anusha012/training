#include<iostream>
using namespace std;

class IDGenerator
{
	static int idval;
public:
	static int getIDVal()
	{
		return ++idval;
	}
};
int IDGenerator::idval=0;

class Student
{
	int marks;
	static int InstRegNo;
	int id;
public:
	Student(int m):marks(m),id(IDGenerator::getIDVal())
	{}
	

	static void disp(const Student &r)
	{
		cout<<InstRegNo<<" "<<r.marks<<" "<<r.id<<endl;
	}
};

int Student::InstRegNo=23;

void main()
{
	Student s1(88);
	Student s2(99);
	Student::disp(s1);
	Student::disp(s2);
	//cout<<Student::InstRegNo<<endl;
}

	