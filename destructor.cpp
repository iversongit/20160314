 ///
 /// @file    destructor.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-14 03:16:19
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A{
	public:
		A(int x=0): _x(x)
		{
			cout<<"A(int)"<<endl;
		}

		~A(){
			cout<<"~A()"<<endl;
		}

	private:
		int _x;
};

class B{
	public:
		B(){
			cout<<"B()"<<endl;
		}

		~B(){
			cout<<"~B()"<<endl;
		}
};

class C : public A{
	public:
		C(int x=0, int y=0)
		:A(x)
		,b()
		,_ix(y)
		{
			cout<<"C(int,int)"<<endl;
		}
//执行派生类对象的析构函数时，基类的析构函数
//会自动被调用
		~C(){
			cout<<"~C()"<<endl;
		}

	private:
		int _ix;
		B b;
};

int main(void){
	C c(6,8);
	return 0;
}
