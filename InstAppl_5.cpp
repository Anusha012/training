#include<iostream>
using namespace std;

class Student
{
private:
	mutable  char *stuName;//const char * stuName;
	mutable int stuMarks;//const int stuMarks;

public:
	
	Student(char *n="Jack", int stuMarks=77):stuMarks(stuMarks),stuName(new char[strlen(n)+1])
	{
		cout<<"par"<<endl;
		strcpy(stuName,n);
	
		
	}


	

	~Student()
	{
		cout<<"destr"<<endl;
		delete [] stuName;
	}

	void dispStuDetails()const 
	{
		
		cout<<"Name:"<<stuName<<endl;
		cout<<"Marks:"<<stuMarks<<endl;
		cout<<"---------------------------------"<<endl;
	}

	void modify()const //const int stuMarks
	{
		stuMarks +=10;
		cout<<stuMarks<<endl;
	}
};

int main()
{
   const Student s1("Shobha",66);
   s1.dispStuDetails();
   s1.modify();
	return 0;
}
















