#include<iostream>
#include<iterator>
using namespace std;
int main()
{
	cout<<"Enter 2 integers"<<endl;
	//creating istream_iterator for reading inputs from cin
	std::istream_iterator<int> inputInt(cin);

	int number1 = *inputInt;//read int from standard input
	inputInt++;//move itertaor to the next input
	int number2 = *inputInt;//read int from standard input
	
	//create ostream_iterator for writin int values to cout
	std::ostream_iterator<int> outputInt(cout);
	cout<<"The sum is : ";
	*outputInt = number1 + number2;
	cout<<endl;
	
}
