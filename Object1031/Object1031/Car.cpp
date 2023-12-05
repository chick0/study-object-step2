#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Car {
private:
	string carNo;
	char* factory;
public:
	Car(string no, const char* factory) {
		carNo = no;
		this->factory = new char[strlen(factory) + 1];
		strcpy(this->factory, factory);
	}

	void Show() {
		cout << "차량번호: " << carNo << endl;
		cout << "제조사: " << factory << endl;
	}
};

class Automobile : Car {
private:
	string model;
public:
	Automobile(string no, const char* factory, string m) : Car(no, factory) {
		model = m;
	}

	void Show() {
		Car::Show();
		cout << "모델명: " << model << endl;
		cout << "-------------------" << endl;
	}
};

int main() {
	Automobile* pt[3];
	pt[0] = new Automobile("14다 4399", "기아", "K5");
	pt[1] = new Automobile("10가 1234", "기아", "K7");
	pt[2] = new Automobile("13가 5555", "기아", "K9");

	for (int i = 0; i < 3; i++) {
		pt[i]->Show();
	}

	for (int i = 0; i < 3; i++) {
		delete pt[i];
	}

	return 0;
}
