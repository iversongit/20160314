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
			cout << "_pstr-->" << _pstr <<" , ";
		}
	private:
		char *_pstr;
};

class Derived : public Base{
	public:
		Derived(const char * pstr1,const char * pstr2)
		:Base(pstr1)
		{
			cout<<"Derived(const char *)"<<endl;
			_pstr1 = new char[strlen(pstr2) + 1];
			strcpy(_pstr1,pstr2);
		}

		Derived(const Derived & rhs)
		:Base(rhs)  //显式调用
		{
			cout<<"Derived(const Derived &)"<<endl;
			_pstr1 = new char[strlen(rhs._pstr1) + 1];
			strcpy(_pstr1,rhs._pstr1);
		}

		Derived & operator =(const Derived & rhs){
			cout<<"operator =(const Derived &)"<<endl;
			Base::operator =(rhs);  //显式调用
			if(this != &rhs){
				delete[] _pstr1;
				_pstr1 = new char[strlen(rhs._pstr1) + 1];
				strcpy(_pstr1,rhs._pstr1);
			}
			return *this;
		}

		~Derived(){
			cout<<"~Derived()"<<endl;
			delete[] _pstr1;
		}

		void print(){
			Base::print();
			cout<<"_pstr1-->"<<_pstr1<<endl;
		}
	private:
		char *_pstr1;
};

int main(void){
	Derived d1("hello","world");
	d1.print();
	cout<<"----------------------"<<endl;
	Derived d2("thank","you");
	d2.print();
	cout<<"----------------------"<<endl;
	d1 = d2;
	d1.print();
	cout<<"----------------------"<<endl;
	Derived d3(d1);
	d3.print();
	return 0;
}
