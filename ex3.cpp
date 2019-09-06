#include<iostream>
#include<string.h>
#include<malloc.h>
#include<typeinfo.h>

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
	
	Book *books[MAX_BOOKS];
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
		int i=0;
		for ( i=0;i<bookCount;i++)
		{
			if(strcmp(books[i]->bookTitle,bookTitle)==0)
			{
				books[i]->bookStock += bookStock;
				break;
			}
		}
		//BOOK NOT PRESENT
		if (i==bookCount)
		{
			switch(bookType)
			{
				case TECHBOOK:
					books[bookCount] = new TechnicalBook(bookTitle, bookCost,bookStock);
					break;
				case MANGBOOK:
					books[bookCount] = new ManagmentBook(bookTitle, bookCost,bookStock);
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
		
		for(int i=0;i<bookCount;i++)
		{
			
			if (bookType==TECHBOOK && typeid(*books[i])==typeid(TechnicalBook))
				books[i]->displayBookDetails();
			else if (bookType==MANGBOOK && typeid(*books[i])==typeid(ManagmentBook))
				books[i]->displayBookDetails();
			else if(bookType == ALLBOOKS)
				books[i]->displayBookDetails();
		}
	}
	
	void deleteBookEntry(int index)
	{
		delete books[index];
		books[index] = books[bookCount-1];
		books[bookCount-1] = NULL;
		bookCount --;
	}
	
	void searchBook(char * bookTitle, int quantity)
	{
		int i;
		char choice;
		for ( i=0;i<bookCount;i++)
		{
			if(strcmp(books[i]->bookTitle,bookTitle)==0)
			{
				if (quantity <= books[i]->bookStock)
				{
					cout<<"Book Available with sufficient stock"<<endl;
					cout<<"Billing Cost : "<<quantity*books[i]->bookCost<<endl;
					if (typeid(*books[i])==typeid(TechnicalBook))
						cout<<"Cost after discount : "<<(float)quantity*(1-(((TechnicalBook*)books[i])->getROD()))*(float)books[i]->bookCost<<endl;
					else if (typeid(*books[i])==typeid(ManagmentBook))
						cout<<"Cost after discount : "<<(float)quantity*(1-(((ManagmentBook*)books[i])->getROD()))*(float)books[i]->bookCost<<endl;
					cout<<"Enter y to purchase"<<endl;
					cin>>choice;
					if (choice == 'y')
					{
						books[i]->bookStock -= quantity;
						
						if (books[i]->bookStock == 0)
							deleteBookEntry(i);			
					}	
				}
				else
					cout<<"Book Available but stock is limited"<<endl;
				break;
			}
		}	
		if (i == bookCount)
				cout<<"Book not Available"<<endl;
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


