//Inheritance Demo
#include<iostream>
using namespace std;

class Book
{
private:
	char *BookTitle;
	double BookCost;
	int BookStock;

public:
	Book(char *title,double cost,int stock):BookTitle(new char[strlen(title)+1]),BookCost(cost),BookStock(stock)
	{
		strcpy(BookTitle,title);
	}
	char* getBookTitle()
	{
		return BookTitle;
	}

	double getBookCost()
	{
		return BookCost;
	}

	int getBookStock()
	{
		return BookStock;
	}

	void setBookStock(int updatedstock)
	{
		BookStock=updatedstock;
	}
	virtual ~Book()
	{
		if(BookTitle)
			delete [] BookTitle;
	}
};

class TechnicalBook : public Book
{
private:
	static double rateOfDisc;
public:
	TechnicalBook(char *title,double cost,int stock):Book(title,cost,stock)
	{}
	double getRateOfDisc()
	{
		return rateOfDisc;
	}
};

double TechnicalBook::rateOfDisc=0.05;

class ManagementBook : public Book
{
	private:
	static double rateOfDisc;
public:
	ManagementBook(char *title,double cost,int stock):Book(title,cost,stock)
	{}
	double getRateOfDisc()
	{
		return rateOfDisc;
	}
};
double ManagementBook::rateOfDisc=0.10;


class BookStore
{
	static char *BookStoreName;
	Book *b[3];
	int BookCount,MaxCount;
	BookStore():BookCount(0),MaxCount(3)
	{
		for(int i=0;i<3;i++)
			b[i]=NULL;
	}
	static BookStore *bs;
public:

	static BookStore* CreateInstance()
	{
		if(bs==NULL)
			bs=new BookStore();
		return bs;
	}

	static void DeleteInstance()
	{
		if(bs)
			delete bs;
	}


	 void AddBook()
	{
		int choice;
		char title[25];
		double cost;
		int stock;
		int status=false;

        		
			cout<<"1:Add a TechnicalBook "<<endl;
			cout<<"2:Add a Management Book"<<endl;
			cout<<"Enter your choice"<<endl;
			cin>>choice;
			cout<<"enter the title"<<endl;
			cin>>title;
			//Check for availability of the book
			int pos=-1;
			for(int i=0;i<BookCount;i++)
			{
				if(b[i]!=NULL)
				{
					if(strcmp(b[i]->getBookTitle(),title)==0)
					{
						status=true;
						pos=i;
						break;
					}
				}
			}
			
			
			if(status)
			{
				cout<<"book by the title "<<title<<" exists -> existing stock is updated"<<endl;
				cout<<"enter the stock "<<endl;
				cin>>stock;
				int updatedstock = b[pos]->getBookStock()+stock;
				b[pos]->setBookStock(updatedstock);
				
			}
			else
			{
				if(BookCount==MaxCount)
				cout<<"No more books can be added"<<endl;
				else
				{
					cout<<"book by the title "<<title<< " does not exists -> adding a book to the catalog"<<endl;
					cout<<"enter the cost and stock "<<endl;
					cin>>cost;
					cin>>stock;
					for(int i=0;i<MaxCount;i++)
					{
						if(b[i]==NULL)
						{
							if(choice==1)
								b[i]=new TechnicalBook(title,cost,stock);
							else if(choice==2)
								b[i]=new ManagementBook(title,cost,stock);

							status=true;
							BookCount++;
							break;
						}
					}
				
			   }

			}
	
	}

	

	
	~BookStore()
	{
		for(int i=0;i<MaxCount;i++)
		{
			if(b[i]!=NULL)
			    delete b[i];
		}
	}

	 void DispBook()
	{
		int choice;
		if(BookCount==0)
			cout<<"Catalog is empty"<<endl;
		else
		{
			cout<<"1:Display all books"<<endl;
			cout<<"2:Display technical books only"<<endl;
			cout<<"3:Display management books only"<<endl;
			cout<<"enter your choice"<<endl;
			cin>>choice;

			if(choice==1)
			{
				for(int i=0;i<MaxCount;i++)
				{
					if(b[i]!=NULL)
					{
						cout<<"BookstoreName:"<<BookStoreName<<endl;
						cout<<"Title:"<<b[i]->getBookTitle()<<endl;
						cout<<"Cost:"<<b[i]->getBookCost()<<endl;
						cout<<"Stock:"<<b[i]->getBookStock()<<endl;
						if(typeid(*(b[i]))==typeid(TechnicalBook))
							cout<<"rateofDisc:"<<((TechnicalBook*)b[i])->getRateOfDisc()<<endl;
						if(typeid(*(b[i]))==typeid(ManagementBook))
							cout<<"rateofDisc:"<<((ManagementBook*)b[i])->getRateOfDisc()<<endl;
						cout<<"-----------------------------------"<<endl;
					}
				}
			}

			if(choice==2)
			{
				for(int i=0;i<MaxCount;i++)
				{
					if((b[i]!=NULL)&&(typeid(*(b[i]))==typeid(TechnicalBook)))
					{
						cout<<"BookstoreName:"<<BookStoreName<<endl;
						cout<<"Title:"<<b[i]->getBookTitle()<<endl;
						cout<<"Cost:"<<b[i]->getBookCost()<<endl;
						cout<<"Stock:"<<b[i]->getBookStock()<<endl;
						cout<<"rateofDisc:"<<((TechnicalBook*)b[i])->getRateOfDisc()<<endl;
						cout<<"-----------------------------------"<<endl;
					}
				}
			}
			if(choice==3)
			{
				for(int i=0;i<MaxCount;i++)
				{
					if((b[i]!=NULL)&&(typeid(*(b[i]))==typeid(ManagementBook)))
					{
						cout<<"BookstoreName:"<<BookStoreName<<endl;
						cout<<"Title:"<<b[i]->getBookTitle()<<endl;
						cout<<"Cost:"<<b[i]->getBookCost()<<endl;
						cout<<"Stock:"<<b[i]->getBookStock()<<endl;
						cout<<"rateofDisc:"<<((ManagementBook*)b[i])->getRateOfDisc()<<endl;
						cout<<"-----------------------------------"<<endl;
					}
				}
			}
		}
	}

	 void SearchBook()
	{
		char title[25];
		int stock;

		if(BookCount==0)
			cout<<"Catalog is empty"<<endl;
		else
		{
			cout<<"enter the required title and stock"<<endl;
			cin>>title>>stock;

			char ch;
			double rateofdisc,cost;
			bool status=false;
			for(int i=0;i<MaxCount;i++)
			{
				if(b[i]!=NULL)
				{
					if(strcmp(b[i]->getBookTitle(),title)==0)
					{
						status=true;
						if(stock<=b[i]->getBookStock())
						{
							cout<<"Book available with sufficient stock"<<endl;

							if(typeid(*(b[i]))==typeid(class TechnicalBook))
								rateofdisc =((TechnicalBook*)b[i])->getRateOfDisc();
							
							if(typeid(*(b[i]))==typeid(ManagementBook))
								rateofdisc =((ManagementBook*)b[i])->getRateOfDisc();
							
							cout<<"Billing Cost before Discount:"<<(b[i]->getBookCost()*stock)<<endl;
							cost = (b[i]->getBookCost()*stock);
							cost = cost - (rateofdisc*cost);
							cout<<"Billing Cost After Discount:"<<cost<<endl;
							cout<<"enter y to purchase"<<endl;
							cin>>ch;
							if(ch=='y')
							{
								int availablestock = b[i]->getBookStock()-stock;
								b[i]->setBookStock(availablestock);
								if(b[i]->getBookStock()==0)
								{
									delete b[i];
									b[i]=NULL;
									BookCount--;
								}
							}
							
						}
						else
							cout<<"Book available but stock is insufficient"<<endl;
					}
				}
			}
			if(status==false)
				cout<<"book not available"<<endl;
		}
		
	}
};

char* BookStore::BookStoreName="Gangarams";
BookStore* BookStore::bs=NULL;

int main()
{
	
	int choice;
	BookStore *bs = BookStore::CreateInstance();
	
	do
	{
		cout<<"1:addBook 2:dispBook 3:searchBook"<<endl;
		cout<<"enter your choice"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 1:
			bs->AddBook();
			break;

		case 2:
			bs->DispBook();
			break;

		case 3:
			bs->SearchBook();
			break;

		default:
			cout<<"invalid choice"<<endl;
			break;
		}
		cout<<"enter 1 to continue"<<endl;
		cin>>choice;
	}while(choice==1);

	BookStore::DeleteInstance();
}


