#include<iostream>
#include<mutex>
using namespace std;
//singleton.h

class singleton {
private:
	singleton() {};
	static singleton *p;

public:    
	static mutex mtx; 
	//mutex是在静态成员函数instance()中使用，所以要指定为静态属性
	//静态成员函数只能访问静态成员变量，因为静态成员函数不接收this指针，无法区分非静态成员属于哪一个对象
	static singleton *getInstance();
	int a;
};

//singleton.cpp
//定义static成员时不用加static修饰
singleton *singleton::p = nullptr;
mutex singleton::mtx;
singleton* singleton::getInstance()
{
	if (nullptr == p)
	{
		mtx.lock();
		if(nullptr == p)
			p = new singleton();
		mtx.unlock();
	}
	return p;
}

//main.cpp
int main(void)
{
	singleton * s = singleton::getInstance();
	s->a = 10;
	singleton* s1 = singleton::getInstance();
	s1->a = 13;
	cout << "s -> a = " << s->a << endl;
	//输出13
}