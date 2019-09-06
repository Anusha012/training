#include<iostream>
#include<string.h>
using namespace std;
class StringDemo
{
    char *str;
    public:
    StringDemo() :str( new char[6])
    {   
		strcpy(str , "Hello"); 
	}
	StringDemo(char *str2):str( new char[strlen(str2)])
	{
		strcpy(str , str2); 
	}
    StringDemo(const StringDemo &s):str( new char[strlen(s.str)])
	{
		
		strcpy(this->str , s.str); 
	}
	StringDemo operator+(StringDemo &a)
	{
		
		char *str1=new char[strlen(this->str)+1+strlen(a.str)];
		strcpy(str1,this->str);
	//	cout<<this->str<<"this->str"<<endl;
		StringDemo b(strcat(str1,a.str));
	
		//cout<<b.str<<endl;
		
		return b;
		
	}
	void disp()
	{
		cout<<this->str<<endl;
	}
	void operator+=(char *str)
	{
		char * st = this->str;
		delete [] this->str;
		this->str=NULL;
		this->str=new char[strlen(str)+strlen(st)];
		this->str=strcat(st,str);
	
		
	}

	bool operator==(StringDemo &s)
	{
		if(strcmp(this->str,s.str)==0)
		{
			return true;
		}
		else
			return false;
	}
	char operator[](int index)
	{
	
			return this->str[index];
		
	}
	char * operator()(int i1, int i2)
	{
	//	cout<<this->str;
	int j=0;
	char *str1=new char[i2+1];
		for(int i=i1;i<(i1+i2);i++)
		{
			str1[j]=this->str[i];
			j++;
		}
		
		return str1;
		
	}
    ~StringDemo()
    {   delete [] str;  }
    friend StringDemo operator+(char *ch,StringDemo &s);
    friend ostream& operator<<(ostream &cout , StringDemo &s);
    
};
	ostream& operator<<(ostream &cout , StringDemo &s)
	{
	cout<<s.str;
	return cout;
}
	StringDemo operator+(char *ch,StringDemo &s)
	{
		
		char *str1=new char[strlen(ch)+1+strlen(s.str)];
		strcpy(str1,ch);
	//	cout<<this->str<<"this->str"<<endl;
		StringDemo b(strcat(str1,s.str));
	
		//cout<<b.str<<endl;
		
		return b;
	}
int main()
{
   StringDemo s1;
   StringDemo s2("World");
   StringDemo s3(s2);
   StringDemo s4;

   s4 = s1 + s3;
   s4.disp();
   s4 += "Program"; //s4.operator+=("Program")
   s4.disp();
  cout << "s1="<<s1<<endl ;
   cout << "s2="<<s2<<endl ;
   cout << "s4="<<s4 <<endl;
   if(s1 == s2)
   cout<<"strings are same "<<endl;
   else
   cout<<"strings are different "<<endl;
   StringDemo s5("Oriented");
   char ch[50];
   strcpy(ch,"Object");
   s5 = ch + s5; 
   cout<<s5<<endl;
   cout<< s5[5]<<endl;//s5.operator[](int index)
   cout<<s5(2,5)<<endl;//s5.operator()(int sindex , int eindex)
   return 0;
 }

