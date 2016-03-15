 ///
 /// @file    inheritence.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-14 03:31:39
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Mouth{
	public:
		void eat(){
			cout<<"Mouth::eat()"<<endl;
		}
};

class Eye{
	public:
		void see(){
			cout<<"Eye::see()"<<endl;
		}
};

class Nose{
	public:
		void smell(){
			cout<<"Nose::smell()"<<endl;
		}
};

class Ear{
	public:
		void listen(){
			cout<<"Ear::listen()"<<endl;
		}
};

class Head : public Mouth,public Eye,public Nose,public Ear
{

};

int main(void){
	Head head;
	head.eat();
	head.see();
	head.smell();
	head.listen();
	return 0;
}
