#include <iostream>
using namespace std;

template<typename T1, typename T2>

class Base{
protected:
	T1 value1;
	T2 value2;
public:
	Base(T1 val1,T2 val2) : value1(val1), value2(val2) {}
	virtual ~Base() {
		cout << "Base destructor called" << endl;
	}

	void show() {
		cout << "Base: value1 = " << value1 << ", value2 = " << value2 << endl;
	}
};
template<typename T1, typename T2, typename T3, typename T4>
class child1 : public Base<T1, T2> {
protected:
	T3 value3;
	T4 value4;
public:
	child1(T1 val1, T2 val2, T3 val3, T4 val4) : Base<T1, T2>(val1, val2), value3(val3), value4(val4) {}

	~child1() {
		cout << "child1 destructor called" << endl;
	}

	void show() {
		Base<T1, T2>::show();
		cout << "child1: value3 = " << value3 << ", value4 = " << value4 << endl;
	}
};

template<typename T1, typename T2, typename T5, typename T6>
class child2 : public Base<T1, T2> {
protected:
	T5 value5;
	T6 value6;
public:
	child2(T1 val1, T2 val2, T5 val5, T6 val6) : Base<T1, T2>(val1, val2), value5(val5), value6(val6) {}

	~child2() {
		cout << "child2 destructor called" << endl;
	}

	void show() {
		Base<T1, T2>::show();
		cout << "child2: value5 = " << value5 << ", value6 = " << value6<< endl;
	}
};

int main() {
	child1<int, char, int, char> child1(10, 'a', 20, 'b');

	child1.show();

	child2<int, char, int, char> child2(100, 'a', 200, 'b');

	child2.show();
}