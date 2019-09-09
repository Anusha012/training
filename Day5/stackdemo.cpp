#include<iostream>
#include<stack>
using namespace std;
void main()
{
	//to create a stack of integers
	stack <int> s;

	//to push elements into the stack
	s.push(11);
	s.push(12);
	s.push(13);
	s.push(14);
	cout<<"stack size = "<<s.size()<<endl;
	
	//to retrieve the element on the top of the stack
	cout<<"element on the top of stack = "<<s.top()<<endl;

	//popping all elements of the stack
	cout<<"the elements popped out of the stack"<<endl;
	while(s.size())
	{
		cout<<s.top()<<endl;
		s.pop();
	}

}
