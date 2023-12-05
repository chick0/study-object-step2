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
		cout << "������ȣ: " << carNo << endl;
		cout << "������: " << factory << endl;
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
		cout << "�𵨸�: " << model << endl;
		cout << "-------------------" << endl;
	}
};

int main() {
	Automobile* pt[3];
	pt[0] = new Automobile("14�� 4399", "���", "K5");
	pt[1] = new Automobile("10�� 1234", "���", "K7");
	pt[2] = new Automobile("13�� 5555", "���", "K9");

	for (int i = 0; i < 3; i++) {
		pt[i]->Show();
	}

	for (int i = 0; i < 3; i++) {
		delete pt[i];
	}

	return 0;
}
