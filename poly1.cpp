 ///
 /// @file    poly1.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-14 08:00:27
 ///
 
#include <iostream>
using std::endl;
using std::cout;

class Base{
	public:
		virtual int func(int x){
			cout<<"Base::func(int)"<<endl;
			_x = x;
			return _x;
		}
	private:
		int _x;
};

class Sub : public Base{
	public:
//派生类的虚函数形式必须与基类的形式完全一致
//即使返回值不相同也不行，少了virtual没问题
		virtual int func(int x){
			cout<<"Sub::func(int)"<<endl;
			_ix = x;
			return _ix;
		}
	private:
		int _ix;
};

int main(void){
	Base base;
	Sub sub;
	Base & refa = base;
	cout<<"refa.func(8)-->"<<refa.func(6)<<endl;
	Base & refb = sub;
	/*展现了动态多态*/
	cout<<"refb.func(8)-->"<<refb.func(8)<<endl;
	return 0;
}
