 ///
 /// @file    poly4.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-14 09:08:29
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
	public:
		virtual void display(){
			cout<<"Base::display()"<<endl;
		}

		void call_base1(){
			this->display();
		}

		void call_base2(){
			Base::display();
		}
};

class Child : public Base
{
	public:
		void display(){
			cout<<"Child::display()"<<endl;
		}

		void call_child1(){
			display();
		}

		void call_base1(){
			cout<<"Child::call_base1()"<<endl;
			display();
		}

		void call_base2(){
			cout<<"Child::call_base2()"<<endl;
			Base::display();
		}
};

int main(void){
	Base base;
	Child c1;
	base.call_base1();
	c1.call_child1();
	cout<<"----------------------"<<endl;
	Base * base1 = &base;
	base1->call_base1();
	base1->call_base2();
	cout<<"----------------------"<<endl;
	//会发生虚函数的特性
	base1 = &c1;
	base1->call_base1();
	base1->call_base2();
	return 0;
}
