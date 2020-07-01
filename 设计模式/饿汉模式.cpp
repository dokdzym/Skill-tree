#include<iostream>
using namespace std;
class singleton {
private:
	singleton(){}
	static singleton* p;
public:
	static singleton* getInstance();
	int a;
};

singleton* singleton::p = new singleton();
singleton* singleton::getInstance()
{
	return p;
}

int main() {
	//在主函数运行前，全局对象已经构造完毕
	singleton* s = singleton::getInstance();
	s->a = 10;
	singleton* s1 = singleton::getInstance();
	s1->a = 13;
	cout << "s -> a = " << s->a << endl;
	//输出13
}