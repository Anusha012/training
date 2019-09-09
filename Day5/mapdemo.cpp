#include<iostream>
#include<map>
#include<string>
using namespace std;


int main()
{
	
	//maintaining a set of accounts and its corresponding rate of interest

	typedef map<string,double > BankAccount;

	BankAccount b;
	b["SA"] = 0.02;
	b["CA"] = 0.05;
	b["FG"] = 0.03;

	//displaying the account details
	BankAccount::iterator t;

	for(t=b.begin(); t!=b.end();t++)
	{
		cout<<t->first<<" "<<t->second<<endl;
	}

	//rename the accounts
	b["SavingsAccount"] = b["SA"];
//	b.erase("SA");

	b["CurrentAccount"] = b["CA"];
//	b.erase("CA");
	
	b["fjsfjf"] = b["FG"];
	b.erase("FG");

	//displaying the changed account details
	for(t=b.begin(); t!=b.end();t++)
	{
		cout<<t->first<<" "<<t->second<<endl;
	}

}
