#include<iostream>
#include<mutex>
using namespace std;

class singleton {
private:
	singleton() {
		test();
	}
	static singleton* ptr;
public:
	static singleton* getInstance();
	static mutex mtx;
	void test(); { cout << "test" << endl; }
	int data;
};

void singleton::test() 
{ cout << "test" << endl; }
singleton* singleton::ptr = new singleton();
//mutex mtx;
singleton* singleton::getInstance(){
	mtx.lock();
	return ptr;
}

int main() {
	cout << "test";
	//singleton::test();
	singleton* p = singleton::getInstance();
	p->data = 10;
	p->test();
	cout << "p -> data = " << p->data << endl;
	singleton* p1 = singleton::getInstance();
	p1->data = 15;
	cout << "p -> data = " << p->data << endl;
}