#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class MyString {
private:
	char* str;
	int length;
public:
	MyString() {
		length = 0;
		str = new char[length];
	}

	MyString(const char* in) {
		length = strlen(in) + 1;
		str = new char[length];
		strcpy(str, in);
	}

	MyString(const MyString &copy) {
		str = new char[copy.length];
		length = copy.length;

		strcpy(str, copy.str);
	}

	MyString operator+(const MyString& b) {
		int newLength = length + b.length;
		char *tmp = new char[newLength];
		
		sprintf(tmp, "%s%s", str, b.str);

		delete[] str;
		str = new char[newLength];
		length = newLength;
		strcpy(str, tmp);

		return *this;
	}

	void operator=(const char* in) {
		int newLength = strlen(in) + 1;

		if (length != newLength) {
			delete[] str;
			str = new char[newLength];
			length = newLength;
		}

		strcpy(str, in);
	}

	bool operator==(const MyString &b) const {
		if (length != b.length) {
			return false;
		}

		for (int i = 0; i < length; i++) {
			if (str[i] != b.str[i]) {
				return false;
			}
		}

		return true;
	}

	char operator[](const int index) const {
		if (index < 0 || index >= length) {
			cout << "IndexError";
			exit(1);
		}

		return str[index];
	}

	friend istream& operator>>(istream&, MyString&);
	
	friend ostream& operator<<(ostream&, const MyString&);

	~MyString() {
		delete[] str;
	}
};

istream& operator>>(istream& is, MyString& myStr) {
	char tmp[1024];
	memset(tmp, 0, sizeof(tmp));

	is >> tmp;
	myStr = tmp;

	return is;
}

ostream& operator<<(ostream& os, const MyString& myStr){
	os << myStr.str;
	return os;
}

int main()
{
	MyString A, B;
	cin >> A >> B;

	cout << A << "(와)과 " << B << "(은)는 ";

	if (A == B) {
		cout << "동일하다." << endl;
	}
	else {
		cout << "동일하지 않다." << endl;
	}

	MyString c = A + B;

	cout << "그래서 저 두 스트링을 합치면 '" << c << "' 이다." << endl;

	return 0;
}
