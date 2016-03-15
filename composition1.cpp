 ///
 /// @file    composition1.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-14 05:09:27
 ///
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Base{
	public:
		Base(const char * pstr){
			cout<<"Base(const char *)"<<endl;
			_pstr = new char[strlen(pstr) + 1];
			strcpy(_pstr,pstr);
		}

		Base(const Base & rhs){
			cout<<"Base(const Base &)"<<endl;
			_pstr = new char[strlen(rhs._pstr) + 1];
			strcpy(_pstr,rhs._pstr);
		}

		Base & operator =(const Base & rhs){
			cout<<"operator =(const Base &)"<<endl;
			if(this != &rhs){
				delete[] _pstr;
				_pstr = new char[strlen(rhs._pstr) + 1];
				strcpy(_pstr,rhs._pstr);
			}
			return *this;
		}

		~Base(){
			cout<<"~Base()"<<endl;
			delete[] _pstr;
		}

		void print(){
			cout << "_pstr-->" << _pstr <<endl;
		}
	private:
		char *_pstr;
};

class Derived : public Base{
	public:
		Derived(const char * pstr)
		:Base(pstr)
		{
			cout<<"Derived(const char *)"<<endl;
		}

		~Derived(){
			cout<<"~Derived()"<<endl;
		}

		void print(){
			Base::print();
		}
};

int main(void){
	Derived d1("hello");
	d1.print();
	cout<<"----------------------"<<endl;
	Derived d2("world");
	d2.print();
	cout<<"----------------------"<<endl;
	d1 = d2;
	d1.print();
	return 0;
}
