#include<iostream>
#include<string.h>
using namespace std;

class Student
{
private:
	char *stuName;
	const int stuMarks;
public:
	
	Student(char *n="Jack", int stuMarks=77):stuMarks(stuMarks),stuName(new char[strlen(n)+1]
	{
		cout<<"par"<<endl;
		strcpy(stuName,n);
	
		
	}

	

	~Student()
	{
		cout<<"destr"<<endl;
		delete [] stuName;
	}

	void dispStuDetails()
	{
		cout<<"Name:"<<stuName<<endl;
		cout<<"Marks:"<<stuMarks<<endl;
		cout<<"---------------------------------"<<endl;
	}
};

int main()
{

	Student s[3] = {Student("Shobha",88),Student("Rushil",100)};
   //s[0].Student("Shobha",88);
   for(int i=0;i<3;i++)
	   s[i].dispStuDetails();
	return 0;
}


















