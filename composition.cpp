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

class Head
{
	public:
		void eat(){
			_mouth.eat();
		}

		void listen(){
			_ear.listen();
		}

		void smell(){
			_nose.smell();
		}

		void see(){
			_eye.see();
		}

	private:
		Mouth _mouth;
		Ear   _ear;
		Eye   _eye;
		Nose  _nose;
};

int main(void){
	Head head;
	head.eat();
	head.see();
	head.smell();
	head.listen();
	return 0;
}
