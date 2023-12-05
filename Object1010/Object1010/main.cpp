#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Person {
private:
	char* name;
public:
	Person(const char* name) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	~Person() {
		delete[] name;
	}

	char* GetName() const {
		return name;
	}
};

class Student : public Person {
private:
	char* major;
public:
	Student(const char* name, const char* major) : Person(name) {
		this->major = new char[strlen(major) + 1];
		strcpy(this->major, major);
	}

	void ShowMyInfo() {
		cout << GetName() << endl;
		cout << major << endl;
	}

	~Student() {
		delete[] major;
	}
};

int main() {
	Student std1("장동건", "수학과");
	Student std2("아이유", "게임학과");

	std1.ShowMyInfo();
	std2.ShowMyInfo();

	return 0;
}
