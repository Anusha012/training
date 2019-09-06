#include<iostream>
#include<string.h>
using namespace std;

class bookstore
	{
		public:
		char *name;
		int cost;
		int stock;
		
		bookstore(char *name,int cst,int sto):name(new char[strlen(name)+1])
		{
			strcpy(this->name,name);
			cost=cst;
			stock=sto;
		}
		void display()
		{
			cout<<"name:"<<name<<endl<<"cost:"<<cost<<endl<<"stock:"<<stock<<endl;
		}
		void searchbook(char *name,int stock)
		{
			if(strcmp(this->name,name)==0)
			{
				cout<<"book is available"<<endl;
				if(this->stock>=stock)
				{
					cout<<"take books home:"<<endl;
				}
				else
				{
					cout<<"books are not available:"<<endl;
				}
			}
			
		}
			};
	
	
	int main()
	{
		char name[20];
		int c,s;
		bookstore *b1[3];
		for(int i=0;i<3;i++)
		{
			cout<<"Enter the name of book title"<<endl;
			cin>>name;
			cout<<"Enter the cost and stock"<<endl;
			cin>>c>>s;
			b1[i] = new bookstore(name,c,s);
			
		}
			
	
	
		for(int i=0;i<3;i++)
		b1[i]->display();
		
			cout<<"Enter the name of book title"<<endl;
			cin>>name;
			cout<<"Enter quantity"<<endl;
			cin>>s;
		
		for(int i=0;i<3;i++)
		{
			b1[i]->searchbook(name,s);
		}
		
	
	}
