#include <iostream>
#define MAX_DATA 10
using namespace std;

class Person {
private:
	string name;
	int age;
	string phone;
	bool isInit;
public:
	Person() {
		isInit = false;
	}

	string getName() {
		return name;
	}

	int getAge() {
		return age;
	}

	string getPhone() {
		return phone;
	}

	bool getInit() {
		return isInit;
	}

	void setData(string name, int age, string phone) {
		this->name = name;
		this->age = age;
		this->phone = phone;
		this->isInit = true;
	}
};

void ShowData(Person* ps) {
	if (ps->getInit()) {
		cout << "이름: " << ps->getName() << endl;
		cout << "나이: " << ps->getAge() << endl;
		cout << "번호: " << ps->getPhone() << endl;
		cout << endl;

	}
}

void InputData(Person* ps) {
	string name;
	int age;
	string phone;

	cout << "이름: ";
	cin >> name;

	cout << "나이: ";
	cin >> age;

	cout << "전화번호: ";
	cin >> phone;

	ps->setData(name, age, phone);
}

int main()
{
	Person *ps = new Person[MAX_DATA];
	Person* ptr = ps;

	while (1) {
		int menu;
		cout << "1: 추가\n2. 모두 보기\n메뉴 선택: ";
		cin >> menu;

		switch (menu) {
		case 1:
			int index;
			cout << "순번 선택: ";
			cin >> index;

			if (index < 0 || index > MAX_DATA) {
				cout << "올바른 순번이 아닙니다." << endl;
				break;
			}

			InputData((ptr + index));
			break;

		case 2:
			for (int i = 0; i < MAX_DATA; i++) {
				ShowData((ptr + i));
			}

			break;

		default:
			cout << "등록된 메뉴가 아닙니다.";
			break;
		}
	}

	delete[] ps;
	return 0;
}
