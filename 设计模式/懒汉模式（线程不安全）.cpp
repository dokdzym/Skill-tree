#include<iostream>
#include<mutex>
using namespace std;

class singleton {
private:
	singleton(){}
	static singleton* p;
public:
	static singleton* getInstance();
	int data;
};

singleton* singleton::p = nullptr;
singleton* singleton::getInstance() {
	if (nullptr == p)
		p = new singleton();
	return p;
}

int main() {
	singleton* s = getInstance(); 
	s.data = 10;
	cout << s->data << endl;
	singleton* s1 = new singleton();
	s1.data = 13;
	cout << s->data << endl;
}