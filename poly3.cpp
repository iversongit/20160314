 ///
 /// @file    poly2.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-14 08:29:53
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base{
	public:
		virtual 
		void display(){
			cout<<"Base::display()"<<endl;
		}
};

class Child1 : public Base{
	public:
		void display(){
			cout<<"Child1::display()"<<endl;
		}

		void printf(){
			cout<<"Child1::printf()"<<endl;
		}
};

class Child2 : public Base{
	public:
		void display(){
			cout<<"Child2::display()"<<endl;
		}
};

void display(Base * base)
{
	base->display();
}

int main(void){
	Base *pt = NULL;
	Child1 c1;
//通过对象名去调用时，并不表现出虚函数的特性
//跟调用非虚函数是一样的
	c1.display();
	c1.printf();
	c1.Base::display();

//当基类指针或引用指向派生类对象，并通过基类指针
//或引用调用虚函数，此时才发挥虚函数的作用
	Child2 c2;
	pt = &c2;
	pt->display();

	Base &refa = c2;
	refa.display();
	return 0;
}
