 ///
 /// @file    typecast.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-14 07:40:27
 ///
 
#include <iostream>
using std::endl;
using std::cout;

class Point{
public:
	Point(int x,int y)
	:_x(x)
	,_y(y)
	{
		cout<<"Point(int,int)"<<endl;
	}

	int getX() const{
		return _x;
	}

	int getY() const{
		return _y;
	}

	void disp(){
		cout<<"("<<_x<<" , "<<_y<<")"<<endl;
	}

private:
	int _x;
	int _y;
};

class Point3d : public Point{
public:
	Point3d(int x,int y,int z)
	:Point(x,y)
	,_iz(z)
	{
		cout<<"Point3d(int,int,int)"<<endl;
	}

	void display(){
		cout<<"("<<getX()<<" , "<<getY()<<" , "<<_iz<<")"<<endl;
	}
private:
	int _iz;
};

int main(void){
	Point p1(2,2);
	cout<<"p1-->";
	p1.disp();
	cout<<"------------------"<<endl;
	Point3d p2(3,3,3);
	cout<<"p2-->";
	p2.display();
	cout<<"------------------"<<endl;
	Point &refa = p2;
	cout<<"refa-->";
	refa.disp();
	cout<<"------------------"<<endl;
	Point *pt = &p2;
	cout<<"pt-->";
	pt->disp();
	cout<<"------------------"<<endl;
	p1 = p2;
	cout<<"p1-->";
	p1.disp();
	return 0;

}
