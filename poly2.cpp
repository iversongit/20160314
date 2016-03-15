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
	cout<<"sizeof(Base)-->"<<sizeof(Base)<<endl;
	cout<<"sizeof(Child1)-->"<<sizeof(Child1)<<endl;
	Base *pt = NULL;
	Base base;
	Child1 c1;
	c1.display();
	Child2 c2;
	pt = &c2;
	pt->display();
	cout<<"-----------------------"<<endl;
	pt->display();
	pt = &c1;
	pt->display();
	pt = &c2;
	pt->display();


	display(&base);
	display(&c1);
	display(&c2);
	return 0;
}
