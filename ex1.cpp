#include<iostream>
#include<string.h>
using namespace std;

class Book
{
	char* bookTitle;
	int bookCost;
	int bookStock;
public:
	Book(char * bookTitle, int bookCost, int bookStock)
	{
		this->bookTitle = bookTitle;
		this->bookCost = bookCost;
		this->bookStock = bookStock;
	}
	void displayBookDetails()
	{
		cout<<"Book Title :"<<bookTitle;
		cout<<" Book Cost :"<<bookCost;
		cout<<" Book Stock :" <<bookStock<<endl;
	}
	bool searchForBook(char * title, int quantity)
	{

		
		if(strcmp(bookTitle,title)==0)
		{
			if (quantity <= bookStock)
			{
				cout<<"Book Available with sufficient stock"<<endl;
				cout<<"Biling Cost : "<<quantity*bookCost<<endl;				
			}
			else
				cout<<"Book Available but stock is limited"<<endl;
			return true;
		}
		return false;
	}
};
int main()
{
	char name[20];
	int quantity,i;

	Book b[3] = {Book("Java",100,10),Book("C++",150,12),Book("C",80,2)};
	for(i=0;i<3;i++)
		b[i].displayBookDetails();
	cout<<"Enter book name"<<endl;
	cin>>name;
	cout<<"Enter quantity"<<endl;
	cin>>quantity;

	for(i=0;i<3;i++)
		if(b[i].searchForBook(name,quantity))
			break;
	if(i==3)
		cout<<"Book not Available"<<endl;
return 0;
}


