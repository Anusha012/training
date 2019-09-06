#include<iostream>
using namespace std;
class Institute
{
	class Student
{
	int marks;
	int regno;
	
public:
	Student(int m=0 , int r=0):marks(m),regno(r)
	{
	
	}
	int getMarks()
	{
		return marks;
	}
	int getRegNo()
	{
		return regno;
	}
	void setMarks(int uM)
	{
		marks=uM;
	}
	
};


	Student *s[3];
	int stuCount;
public:
	Institute():stuCount(0)
	{
		for(int i=0;i<3;i++)
		s[i]=NULL;
	}
	void RegisterStudent()
	{
		int m , r;
		if(stuCount<3)
		{
			cout<<"enter the marks and regno"<<endl;
			cin>>m>>r;
			s[stuCount] = new Student(m,r);
			stuCount++;
		}
		else
			cout<<"Registration failed"<<endl;
	}

	void DisplayStudentDetails()
	{
		if(stuCount==0)
			cout<<"Students are not registered yet"<<endl;
		else
		{
			for(int i=0;i<3;i++)
			{
				if(s[i]!=NULL)
					cout<<s[i]->getMarks()<<" "<<s[i]->getRegNo()<<endl;
			}
		}

	}

	void searchByRegNo(int r)
	{
		bool status=false;
		if(stuCount==0)
			cout<<"Students are not registered yet"<<endl;
		else
		{
			for(int i=0;i<stuCount;i++)
			{
				if(s[i]->getRegNo()==r)
				{
					status=true;
					delete s[i];
					s[i]=NULL;
					stuCount--;
					cout<<"Record is deleted"<<endl;
					break;
				}
		
			if(status==false)
				cout<<"Student record not found"<<endl;
		}
	}

	~Institute()
	{
		for(int i=0;i<stuCount;i++)
		{
			if(s[i]!=NULL)
			{
				delete s[i];
				s[i]=NULL;
			}
		}
	}
};

void main()
{
	
	Institute inst;
    Student s(22,2);
	int choice=0;
	do
	{
	cout<<"1:Register Student"<<endl;
	cout<<"2:Display the student details"<<endl;
	cout<<"3:Search by Regno"<<endl;
	cout<<"enter the choice"<<endl;
	
	cin>>choice;
	switch(choice)
	{
	case 1:
		inst.RegisterStudent();
		break;
	case 2:
		inst.DisplayStudentDetails();
		break;
	case 3:
		inst.searchByRegNo(2);
		break;
	};
	cout<<"enter 1 to continue"<<endl;
	cin>>choice;
	}while(choice==1);
}


