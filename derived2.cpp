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

		int _ix;
#endif

};

//如果子类没有提供构造函数，则系统会自动提供一个
//无参构造函数，当创建子类对象时，会去自动调用
//基类的无参构造函数，此时，基类必须提供一个无参
//构造函数
class Derived : public Base
{
	public:
#if 0
		Derived()
		{
			cout<<"Derived()"<<endl;
		}

		Derived(int x)
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
	cout<<"d._ix -->"<<d._ix<<endl;
	return 0;
}
