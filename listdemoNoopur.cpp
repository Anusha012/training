#include<iostream>
#include<string.h>
#include<malloc.h>
#include<typeinfo.h>
#include<list>
#define MAX_BOOKS 3
#define TECHBOOK 1
#define MANGBOOK 2
#define ALLBOOKS 3
using namespace std;

class Book
	{
	public:
		char *bookTitle;
		int bookCost;
		int bookStock;
	public:
		Book(char  * bookTitle, int bookCost, int bookStock)
		{
			this->bookTitle = new char[strlen(bookTitle)+1];
			strcpy(this->bookTitle,bookTitle);
			this->bookCost = bookCost;
			this->bookStock = bookStock;
		}
		void displayBookDetails()
		{
			cout<<"Book Title :"<<bookTitle;
			cout<<" Book Cost :"<<bookCost;
			cout<<" Book Stock :" <<bookStock<<endl;
		}
		virtual ~Book()
		{
		
		}

	};

class TechnicalBook:public Book
{
	
	static float rateOfDis;
	public :
		
		TechnicalBook(char  * bookTitle, int bookCost, int bookStock):Book(bookTitle, bookCost, bookStock)
		{ 
			
		}
		
		static float getROD()
		{
			return rateOfDis;
		}
	
};

class ManagmentBook:public Book
{
	static float rateOfDis;
	public :
		ManagmentBook(char  * bookTitle, int bookCost, int bookStock):Book(bookTitle, bookCost, bookStock)
		{ 
			
		}
		
		static float getROD()
		{
			return rateOfDis;
		}
};

float TechnicalBook::rateOfDis = 0.05;
float ManagmentBook::rateOfDis = 0.10;

class BookStore{
	
	list <Book *> l;
	list <Book *> ::iterator it;
	int bookCount;
	
public:
	BookStore():bookCount(0)
	{ }
	
	
	void addBook(char  *bookTitle, int bookCost, int bookStock, int bookType)
	{
		//BOOKSTORE CAPACITY REACHED
		if (bookCount == MAX_BOOKS)
		{
			cout<<"Store capacity to hold books reached its limit...cannot add more books";
			return;
		}
		//SEARCH IF BOOK IS PRESENT IN STORE
	
		for ( it=l.begin();it!=l.end();it++)
		{
			if(strcmp((*it)->bookTitle,bookTitle)==0)
			{
				(*it)->bookStock += bookStock;
				break;
			}
		}
		//BOOK NOT PRESENT
		if (it==l.end())
		{
			switch(bookType)
			{
				case TECHBOOK:
					l.push_back( new TechnicalBook(bookTitle, bookCost,bookStock));
					break;
				case MANGBOOK:
				l.push_back(new ManagmentBook(bookTitle, bookCost,bookStock));
					break;
			}

			bookCount++;
		}	
	}
	
	void displayBooks(int bookType)
	{
		if (bookCount==0)
		{
			cout<<"Store is Empty"<<endl;
			return;
		}
		if(bookType==3)
		{
		
			for ( it=l.begin();it!=l.end();it++)
			
			{
				(*it)->displayBookDetails();
				
				/*if (bookType==TECHBOOK && typeid(*books[i])==typeid(TechnicalBook))
					books[i]->displayBookDetails();
				else if (bookType==MANGBOOK && typeid(*books[i])==typeid(ManagmentBook))
					books[i]->displayBookDetails();
				else if(bookType == ALLBOOKS)
					books[i]->displayBookDetails();*/
			}
		}
		else
		{
			for ( it=l.begin();it!=l.end();it++)
			
			{
			//	(*it)->displayBookDetails();
			cout<<typeid(*(*it)).name()<<typeid(TechnicalBook).name();
				if (bookType==TECHBOOK && typeid(*(*it))==typeid(TechnicalBook))
					(*it)->displayBookDetails();
				else if (bookType==MANGBOOK &&typeid(*(*it))==typeid(ManagmentBook))
					(*it)->displayBookDetails();
			}	
		}
	}
	
	void deleteBookEntry(int index)
	{
		cout<<index<<"\t"<<*it<<endl;
		advance(it,index);
	  delete (*it);
	  l.remove(*it);
		/*delete books[index];
		books[index] = books[bookCount-1];
		books[bookCount-1] = NULL;
		bookCount --;*/
	}
	
	void searchBook(char * bookTitle, int quantity)
	{
		int i;
		char choice;
		for ( it=l.begin();it!=l.end();it++)
		{
			if(strcmp((*it)->bookTitle,bookTitle)==0)
			{
				if (quantity <= 	(*it)->bookStock)
				{
					cout<<"Book Available with sufficient stock"<<endl;
					cout<<"Billing Cost : "<<quantity*	(*it)->bookCost<<endl;
					if (typeid(	(*it))==typeid(TechnicalBook))
						cout<<"Cost after discount : "<<(float)quantity*(1-(((TechnicalBook*)	(*it))->getROD()))*(float)	(*it)->bookCost<<endl;
					else if (typeid(	(*it))==typeid(ManagmentBook))
						cout<<"Cost after discount : "<<(float)quantity*(1-(((ManagmentBook*)	(*it))->getROD()))*(float)	(*it)->bookCost<<endl;
					cout<<"Enter y to purchase"<<endl;
					cin>>choice;
					if (choice == 'y')
					{
						(*it)->bookStock -= quantity;
						
						if ((*it)->bookStock == 0)
							deleteBookEntry(i);			
					}	
				}
				else
					cout<<"Book Available but stock is limited"<<endl;
				break;
			}
		}	
		if (	it==l.end())
				cout<<"Book not Available"<<endl;
	}
	
	
	
	~BookStore()
	{
		 for(it=l.begin();it != l.end();)
   {
	  
	 
	  
	  delete (*it);
	  l.remove(*it);
	  it++;
	  
   }
	}
};

int main()
{
	char name[20];
	int quantity,cost;
	int choice,bookType;
	BookStore store;
	cout<<"Welcome to the book Store !!!"<<endl;
	while(1)
	{
		cout<<"Enter 1: To Add books "<<endl<<"Enter 2: To display book details"<<endl<<"Enter 3: To make a purchase"<<endl<<"Enter 4: To exit"<<endl;
		cin >> choice;
		switch(choice){
			case 1:
				cout<<"Type of Book:"<<endl<<TECHBOOK<<". Technical "<<endl<<MANGBOOK<<". Managment "<<endl;
				cin>>bookType;
				cout<<"Enter book Title"<<endl;
				cin>>name;
				cout<<"Enter cost and quantity"<<endl;
				cin>>cost>>quantity;
				store.addBook(name,cost,quantity,bookType);
				break;
			case 2:
				cout<<"Enter the type of book to view : "<<endl<<TECHBOOK<<". Technical "<<endl<<MANGBOOK<<". Managment "<<endl<<ALLBOOKS<<". All Books "<<endl;
				cin>>bookType;
				store.displayBooks(bookType);
				break;
			case 3:
				cout<<"Enter the book title"<<endl;
				cin>>name;
				cout<<"Enter the quantity"<<endl;
				cin>>quantity;
				store.searchBook(name,quantity);
				break;
			case 4:
				exit(0);
				break; 
		
		}
			
		
	}
		
return 0;
}


