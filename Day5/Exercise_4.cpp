//Operator Overloading
#include<iostream>
#include<cstring>
using namespace std;

class StringDemo
{
  char *str;
public:

	StringDemo(char *s="Hello"):str(new char[strlen(s)+1])
	{
		cout<<"par"<<endl;
		strcpy(str,s);
	}

	StringDemo(const StringDemo &s):str(new char[strlen(s.str)+1])
	{
		cout<<"copy"<<endl;
		strcpy(str,s.str);
	}

	StringDemo operator+(StringDemo &s3)
	{
		cout<<"+"<<endl;
		StringDemo temp;
		delete [] temp.str;
		temp.str = new char[strlen(str)+strlen(s3.str)+1];
		strcpy(temp.str,str);
		strcat(temp.str,s3.str);
		return temp;


	}

	void operator=(StringDemo &temp)
	{
		
		cout<<"="<<endl;
		delete [] str;
		str = new char[strlen(temp.str)+1];
		strcpy(str,temp.str);
	}
	~StringDemo()
	{
		delete [] str;
	}

	void disp()
	{
		cout<<str<<endl;
	}

	void operator += (char *s)
	{
      	  char s1[50];
	  strcpy(s1,str);
	  delete [] str;
	  str = new char[strlen(s1)+strlen(s)+1];
	  strcpy(str,s1);
	  strcat(str,s);
	}
	friend ostream& operator<<(ostream &cout,StringDemo &s1);

    	bool operator == (StringDemo &s2)
	{
		if(strcmp(str,s2.str)==0)
			return true;
		else
			return false;
	}
	friend StringDemo operator+(char *ch,StringDemo &s5);

	char operator[](int index)
	{
		return str[index];
	}

};

ostream& operator<<(ostream &cout,StringDemo &s1)
{
	cout<<s1.str<<endl;
	return cout;
}

StringDemo operator+(char *ch,StringDemo &s5)
{
		cout<<"+ friend "<<endl;
		StringDemo temp;
		delete [] temp.str;
		temp.str = new char[strlen(ch)+strlen(s5.str)+1];
		strcpy(temp.str,ch);
		strcat(temp.str,s5.str);
		return temp;
}





int main()
{
   StringDemo s1;
   StringDemo s2("World");
   StringDemo s3(s2);
   StringDemo s4;
 //  s4 = s1 + s3;//s4=temp; s4.operator=(temp)
   s4.disp();
   s4 += "Program";// s4.operator+=("Program");
   s4.disp();
   cout << "s1="<<s1<<endl ;//ostream& operator<<(cout,s1)
   cout << "s2="<<s2<<endl ;
   cout << "s4="<<s4 <<endl;
   if(s1 == s2)//s1.operator == (s2)
   cout<<"strings are same "<<endl;
   else
   cout<<"strings are different "<<endl;
   StringDemo s5("Oriented");
   char ch[50];
   strcpy(ch,"Object");
//   s5 = ch + s5; 
   cout<<s5<<endl;
   cout << s5[5]<<endl;//s5.operator[](int index)

 }

