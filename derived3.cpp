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
#if 1
		Base() : _ix(888)
		{
			cout<<"Base()"<<endl;
		}


		Base(int ix) : _ix(ix)
		{
			cout<<"Base(int)"<<endl;
		}

		~Base(){
			cout<<"~Base()"<<endl;
		}

		void disp(){
			cout<<"_ix -->"<<_ix<<endl;
		}

		int _ix;
#endif

};

class Derived : public Base
{
	public:
#if 1
		Derived() : Base()
		{
			cout<<"Derived()"<<endl;
		}

		Derived(int x,int y) : Base(y)
		{
			cout<<"Derived(int)"<<endl;
		}

		~Derived(){
			cout<<"~Derived()"<<endl;
		}
#endif

};

int main(void){
	Derived d;
	d.disp();
	cout<<"-----------------"<<endl;
	Derived d1(6,6);
	d1.disp();
	return 0;
}
