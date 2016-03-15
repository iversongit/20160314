 ///
 /// @file    derived.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-14 02:16:24
 ///
 
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Base{
	public:
		Base() : _ix(888)
		{
			cout<<"Base()"<<endl;
		}

		~Base(){
			cout<<"~Base()"<<endl;
		}

		int _ix;
};

class Derived : public Base
{
	public:
		Derived(){
			cout<<"Derived()"<<endl;
		}

		Derived(int x){
			cout<<"Derived(int)"<<endl;
		}

		~Derived(){
			cout<<"~Derived()"<<endl;
		}
};

int main(void){
	Derived d(6);
	cout<<"d._ix -->"<<d._ix<<endl;
	return 0;
}
