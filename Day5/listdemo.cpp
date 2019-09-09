#include<iostream>
#include<list>
using namespace std;

class Emp
{
	int EmpSal;
public:
	Emp():EmpSal(12)
	{
		cout<<"in def constr"<<endl;
	}

	Emp(int s):EmpSal(s)
	{
		cout<<"in par constr"<<endl;
	}
	
	Emp(const Emp &x)
	{
		cout<<"copy cons\n";
	}

	void disp()
	{
		cout<<EmpSal<<endl;
	}
	~Emp()
	{
		cout<<"destr"<<endl;
	}

	
};

int main()
{

   list<Emp> v; 
   list<Emp>::iterator t;
 //  Emp *e=new Emp(22);
  Emp e;
  Emp x;
  x=e;
   v.push_back(e);
 //  v.push_back(Emp(11));
  // for(t=v.begin();t != v.end();t++)
//	  (*t).disp();







	
/*
   list<Emp*> v1;
   list<Emp*>::iterator t1,t2;

   Emp *p = NULL;
   v1.push_back(new Emp(11));
   v1.push_back(new Emp(22));
   v1.push_back(new Emp(33));
   cout<<v1.size()<<endl;

   for(t1=v1.begin();t1 != v1.end();)
   {
	  (*t1)->disp();
	  t2 = t1;
	  t1++;
	  delete (*t2);
	  v1.remove(*t2);
	  
   }


*/
   
}


