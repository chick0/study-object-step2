#include <iostream>
using namespace std;

class Number {
private:
	int number;
public:
	Number() {
		number = 0;
	}

	Number(int data) : number(data) {};

	Number operator+(const Number& n) {
		return Number(number + n.number);
	}

	void Show() {
		cout << number << endl;
	}
};

int main() {
	Number a(5);
	Number b(3);
	Number c;

	c = a + b;
	c.Show();

	return 0;
}
