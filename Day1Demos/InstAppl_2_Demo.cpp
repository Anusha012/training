#include<iostream>
#include<string.h>>
using namespace std;

class Student
{
private:
	char *stuName;
	const int stuMarks;
public:
	Student():stuMarks(77),stuName(new char[5])
	{
		cout<<"def"<<endl;
		strcpy(stuName,"Jack");
	
	}
	Student(char *n , int stuMarks):stuMarks(stuMarks),stuName(new char[strlen(n)+1])
	{
		cout<<"par"<<endl;
		strcpy(stuName,n);
	
		
	}

	Student(const Student &st):stuMarks(st.stuMarks),stuName(new char[strlen(st.stuName)+1])
	{
		cout<<"copy"<<endl;
		strcpy(stuName,st.stuName);
	
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

   //Student &r = Student();
   //r.dispStuDetails();
	
    Student s1;
	s1.dispStuDetails();
	
	char n[25];
	int m;
	cout<<"enter the name and marks"<<endl;
	cin>>n>>m;
	Student s2(n,m);
	s2.dispStuDetails();

	Student s3(s2);
	s3.dispStuDetails();
	return 0;
}


















