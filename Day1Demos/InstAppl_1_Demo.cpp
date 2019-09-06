#include<iostream>
#include<string.h>
using namespace std;

class Student
{
private:
	char stuName[25];
	int stuMarks;
public:
	void setStuDetails()
	{
		cout<<"def"<<endl;
		strcpy(stuName,"Jack");
		stuMarks=77;
	}
	void setStuDetails(char *n , int stuMarks)
	{
		cout<<"par"<<endl;
		strcpy(stuName,n);
		this->stuMarks=stuMarks;
		
	}

	void setStuDetails(const Student &st)
	{
	//	st.stuMarks=9;
		cout<<"copy"<<endl;
		strcpy(stuName,st.stuName);
		stuMarks=st.stuMarks;
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

    Student s1;
	//s1.setStuDetails();
	s1.dispStuDetails();
	
	char n[25];
	int m;
	cout<<"enter the name and marks"<<endl;
	cin>>n>>m;
	Student s2;
	s2.setStuDetails(n,m);
	s2.dispStuDetails();

	Student s3;
	s3.setStuDetails(s2);
	s3.dispStuDetails();
	s2.dispStuDetails();
	return 0;
}


















