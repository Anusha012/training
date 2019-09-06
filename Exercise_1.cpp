//use of constructor and dynamic memory management
#include<iostream>
#include<string.h>
using namespace std;


class BookStore
{

				class Book
				{
				private:
					char *BookTitle;
					double BookCost;
					int BookStock;
				public:
					Book(char *title,int cost,int stock):BookTitle(new char[strlen(title)+1]),BookCost(cost),BookStock(stock)
					{
						strcpy(BookTitle,title);
					}
					
					~Book()
					{
						if(BookTitle != NULL)
						delete [] BookTitle;
					}
					void setBookStock(int stock)
						{
							BookStock = stock;
						}
					char* getBookTitle()
						{
							return BookTitle;
						}
						int getBookStock()
						{
							return BookStock;
						}
						int getBookCost()
						{
							return BookCost;
						}
						
						
				
				
				};
		Book * book[4];
	int cost;
	char title[20];
	char choice;
	int  stock;
	int count;

	public:
		BookStore()
		{
			count = 0;
		}
		~BookStore()
		{
			delete [] book;
		}
	void addBook()
	{
		cout<<"enter the book name,cost and stock"<<endl;
		cin>>title>>cost>>stock;
		if(isBookAvailable(title))
			{
				cout<<"Book is already present .Do you want to add some stock?";
				cin>>choice;
				
				if(choice == 'y')
					{
						for(int i=0;i<4;i++)
						{
							if(book[i]!=NULL && strcmp(book[i]->getBookTitle(),title)==0)
									book[i]->setBookStock(book[i]->getBookStock()+stock);
						}		
					}
					
					
						
			}
			else
				{
					count++;
					cout<<"New book is added"<<endl;
						for(int i=0;i<4;i++)
						{
							if(book[i]==NULL){
							
									book[i] = new Book(title,cost,stock);
									break;
								}
						}
					
				}
		}
	void dispBookDetails()
	{
		for(int i=0;i<4;i++)
		{
		    if(book[i]!=NULL)
		    	{
				
				cout<<"Title:"<<book[i]->getBookTitle()<<endl;
				cout<<"Cost:"<<book[i]->getBookCost()<<endl;
				cout<<"Stock:"<<book[i]->getBookStock()<<endl;
				cout<<"-----------------------------------"<<endl;
				}
		}
	}		
	bool searchForBook(char title[25],int stock)
	{

		char ch;
		bool status=false;
		for(int i=0;i<4;i++)
			{
					
				if(strcmp(book[i]->getBookTitle(),title)==0)
				{
					status=true;
					if(stock<=book[i]->getBookStock())
					{
						cout<<"Book available with sufficient stock"<<endl;
						cout<<"Billing Cost:"<<((book[i]->getBookCost())*stock)<<endl;
						cout<<"enter y to purchase"<<endl;
						cin>>ch;
						if(ch=='y')
						{
							book[i]->setBookStock(book[i]->getBookStock() - stock);
						//	if(book[i]->getBookStock() == 0)

								//	delete book[i];
						//	dispBookDetails();
						
							
						}
						
					}
					else
						cout<<"Book available but stock is insufficient"<<endl;
						
					return status;
				}
				
				return status;
			}
	}
	bool isBookAvailable(const char* title)
	{
		for(int i=0;i<4;i++)
		{
			if(book[i]!=NULL && strcmp(book[i]->getBookTitle(),title)==0)
				return true;
		}
		return false;
	}
	void stop()
		{
			
		}
	
};

int main()
{
	int i,stock;
	char title[20];
	
	BookStore b1; 
	while(1)
		{
			cout<<"Enter 1: To add book 2:dispBookDetails 3: searchForBook 4: to exit"<<endl;
			cin>>i;
			switch(i)
				{
					case 1 :
							b1.addBook();
							break;
					case 2 : b1.dispBookDetails();
							break;
					case 3 : 
							cout<<"Enter book title and stock"<<endl;
							cin>>title>>stock;
							b1.searchForBook(title,stock);
							if(!b1.searchForBook(title,stock))
								cout<<"Book is not available"<<endl;
							break;
					case 4 : b1.stop();
							
					exit(0) ;
					 
				}
		}
		
	



}


