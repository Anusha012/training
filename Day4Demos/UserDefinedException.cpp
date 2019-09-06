#include<iostream>
#include<string>
using namespace std;

class Exception
{
protected:
	string msg;
public:
	Exception(string s):msg(s)
	{}
	virtual string getMessage()=0;
};


class SpeedViolationException : public Exception
{

public:
	SpeedViolationException(string s):Exception(s)
	{}
	string getMessage()
	{
		return msg;
	}
};

class Vehicle
{
	int speed;
public:
	void setSpeed(int s)
	{
		try
		{
			if(s>80)
				throw new SpeedViolationException("speed exceeded threshhold speed of 80kmph");
			else
				speed=s;
		}
		catch(Exception *e)
		{
			cout<<e->getMessage()<<endl;
		}
	}
};

void main()
{
		Vehicle v;
		v.setSpeed(90);
		cout<<"in main"<<endl;
}