 ///
 /// @file    oversee.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-14 04:24:28
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base{
	public:
		int func(int i){
			cout<<"Base::func(int)"<<endl;
			return _x;
		}
	protected:
		int _x;
};

class Derived : public Base{
	public:
		int func(){
			cout<<"Derived::func()"<<endl;
			_x = 66;//隐藏基类的_ix
			Base::_x = 88;
			return _x;
		}

	private:
		int _x;
};

int main(void){
	Derived d;
	cout<<"d.func()-->"<<d.func()<<endl;
	//d.func(6) 隐藏（父子类，非虚函数，只要函数名相同）
	//如果要使用父类的同名函数，必须使用作用域限定符
	cout<<"d.Base::func(6)-->"<<d.Base::func(6)<<endl;
	return 0;
}

