#include<iostream>
#include<list>
#include<unistd.h>
using namespace std;

int main()
{
	list<char> l;
	list<char>::iterator t;
	list<char>::reverse_iterator t1;

	
		l.push_front('a');
		l.push_front('b');
		l.push_front('c');
		l.push_front('d');
		l.push_front('e');
		l.push_front('f');

	//display in forward direction
	cout<<"display in forward direction"<<endl;
	for(t=l.begin();t != l.end();t++)
		cout<<*t<<" ";
	
	cout<<endl;

	//display in reverse direction
	cout<<"display in reverse direction"<<endl;
	for(t1=l.rbegin();t1 != l.rend();t1++)
		cout<<*t1<<" ";
			sleep(2);
	cout<<endl;

	//display in random fashion
	cout<<"display in random fashion"<<endl;
	for(t = l.begin();t != l.end();advance(t,3)) //advance inbuilt algorithm is used to step the 
                                                                            //iteration pointer by 2 nodes/values.
	cout<<*t<< " ";
	cout<<endl;
	
}
