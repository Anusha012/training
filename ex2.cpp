#include<iostream>
#include<string.h>
#include<malloc.h>
#define MAX_BOOKS 3
using namespace std;

class BookStore{
	
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

	};
	
	Book *books[MAX_BOOKS];
	int bookCount;
	
public:
	BookStore():bookCount(0)
	{ }
	
	
	void addBook(char  *bookTitle, int bookCost, int bookStock)
	{
		if (bookCount == MAX_BOOKS)
		{
			cout<<"Store capacity to hold books reached its limit...cannot add more books";
			return;
		}

		books[bookCount] = new Book(bookTitle, bookCost,bookStock);
		bookCount++;
	}
	
	void displayBooks()
	{
		if (bookCount==0)
		{
			cout<<"Store is Empty"<<endl;
			return;
		}
		
		for(int i=0;i<bookCount;i++)
			books[i]->displayBookDetails();
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
					cout<<"Biling Cost : "<<quantity*books[i]->bookCost<<endl;
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
	int choice;
	BookStore store;
	cout<<"Welcome to the book Store !!!"<<endl;
	while(1)
	{
		cout<<"Enter 1: To Add books "<<endl<<"Enter 2: To display book details"<<endl<<"Enter 3: To make a purchase"<<endl<<"Enter 4: To exit"<<endl;
		cin >> choice;
		switch(choice){
			case 1:
				cout<<"Enter book Title"<<endl;
				cin>>name;
				cout<<"Enter cost and quantity"<<endl;
				cin>>cost>>quantity;
				store.addBook(name,cost,quantity);
				break;
			case 2:
				store.displayBooks();
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


