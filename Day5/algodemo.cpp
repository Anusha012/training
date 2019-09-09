#include<iostream>
#include<algorithm>
using namespace std;

void disp(int a[])
{
for(int z=0;z<10;z++)
		cout<<a[z]<<" ";
	cout<<endl;

}

int main()
{
// mutating algorithm
	int a[10] = {1,2,3,4,5,6,7,8,9,10};

	cout<<"the contents of original array"<<endl;
	disp(a);

	replace(&a[0],&a[10],5,15);

	cout<<"the contents of original array after in-place version"<<endl;
	disp(a);

// non-mutating algorithm
	int x[10] = {1,2,3,4,5,6,7,8,9,10};
	int y[10];
	replace_copy(&x[0],&x[10],&y[0],5,15);

	cout<<"the contents of original array after copying version"<<endl;
	disp(x);
	
	cout<<"the contents of destination array after copying version"<<endl;
	disp(y);
}
