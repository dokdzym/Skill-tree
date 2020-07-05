#include <iostream>
using namespace std;

template <class T>
class sharedPointer {
private:
	int* count;
	T* p;
public:
	int getCount() { return *count; }
	sharedPointer(T* ptr = nullptr) : p(ptr) {
		if (p) {
			count = new int(1);
		}
		else {
			count = new int(0);
		}
	}
	sharedPointer(const sharedPointer& ptr) {
		p = ptr.p;
		count = ptr.count;
		++(*count);
	}
	sharedPointer& operator=(const sharedPointer& ptr) {
		if (p == ptr.p)
			return *this;
		if (p) {
			if (--(*count) == 0) {
				delete count;
				delete p;
				count = nullptr;
				p = nullptr;
			}
		}
		p = ptr.p;
		count = ptr.count;
		++(*count);
		return *this;
	}
	~sharedPointer() {
		if (--(*count) == 0) {
			delete count;
			delete p;
			count = nullptr;
			p = nullptr;
		}
	}
};

int main() {
	sharedPointer<int> sp1(new int(10));
	sharedPointer<int> sp2(sp1);
	sharedPointer<int> sp3(new int(20));
	sp2 = sp3;
	std::cout << sp1.getCount() << std::endl;
	std::cout << sp3.getCount() << std::endl;
}