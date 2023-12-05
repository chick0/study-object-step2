#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class MyFriendInfo {
private:
	char* name;
	int age;
	bool isInit;
public:
	MyFriendInfo(const char* name, const int age) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);

		this->age = age;
	}

	char* GetName() const {
		return name;
	}

	int GetAge() const {
		return age;
	}

	~MyFriendInfo() {
		delete[] name;
	}
};

class MyFriendDetailInfo : public MyFriendInfo {
private:
	char* address;
	char* phone;
public:
	MyFriendDetailInfo(const char* name, const int age, const char* address, const char* phone) : MyFriendInfo(name, age) {
		this->address = new char[strlen(address) + 1];
		strcpy(this->address, address);

		this->phone = new char[strlen(phone) + 1];
		strcpy(this->phone, name);
	}

	char* GetAddress() const {
		return address;
	}

	char * GetPhone() const {
		return phone;
	}

	~MyFriendDetailInfo() {
		delete[] address;
		delete[] phone;
	}
};

void ShowFriendDetail(const MyFriendDetailInfo& mdi) {
	cout << "�̸� : " << mdi.GetName() << endl;
	cout << "���� : " << mdi.GetAge() << endl;
	cout << "�ּ� : " << mdi.GetAddress() << endl;
	cout << "��ȣ : " << mdi.GetPhone() << endl;
}

int main() {
	MyFriendDetailInfo a("�豹��", 24, "��⵵ ��õ��", "010-3423-3330");
	MyFriendDetailInfo b("�̼���", 22, "���� ���ʱ�", "010-3539-9458");

	ShowFriendDetail(a);
	cout << endl;

	ShowFriendDetail(b);

	return 0;
}
