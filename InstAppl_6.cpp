#include<iostream>
using namespace std;

class Student
{
private:
	
	int stuMarks;

public:
	
	explicit Student( int stuMarks=77):stuMarks(stuMarks)
	{
		cout<<"par"<<endl;		
	}

	explicit Student(const Student &r):stuMarks(r.stuMarks)
	{cout<<"copy"<<endl;}

	void dispStuDetails()const 
	{
		cout<<"const method"<<endl;
		cout<<"Marks:"<<stuMarks<<endl;
		cout<<"---------------------------------"<<endl;
	}

	void dispStuDetails()
	{
		cout<<"non- const method"<<endl;
	}

	 static void modify()
	{
		cout<<"static modify"<<endl;
	}
    void modify()
	{
		cout<<"non-static modify"<<endl;
	}

	
};

int main()
{
 Student s1(88);
 s1.dispStuDetails();

// Student::modify();
s1.modify();

 //Student s2(s1);
// s2.dispStuDetails();
	return 0;
}
















