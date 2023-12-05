#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Book {
private:
	char* title;
	char* isbn;
	int price;
public:
	Book(const char* title, const char* isbn, const int price) {
		this->title = new char[strlen(title) + 1];
		strcpy(this->title, title);

		this->isbn = new char[strlen(isbn) + 1];
		strcpy(this->isbn, isbn);

		this->price = price;
	}

	Book(const Book& copy) {
		title = new char[strlen(copy.title) + 1];
		strcpy(title, copy.title);

		isbn = new char[strlen(copy.isbn) + 1];
		strcpy(isbn, copy.isbn);

		price = copy.price;
	}

	~Book() {
		delete[] title;
		delete[] isbn;
	}
	
	friend void ShowBookInfo(const Book&);
};

class EBook : public Book {
private:
	char* DRMKey;
public:
	EBook(const char* title, const char* isbn, const int price, const char* drm) : Book(title, isbn, price) {
		DRMKey = new char[strlen(drm) + 1];
		strcpy(DRMKey, drm);
	}

	~EBook() {
		delete[] DRMKey;
	}

	friend void ShowBookInfo(const EBook&);
};

void ShowBookInfo(const Book& bk) {
	cout << "제목 " << bk.title << endl;
	cout << "ISBN " << bk.isbn << endl;
	cout << "가격 " << bk.price << "원" << endl;
}

void ShowBookInfo(const EBook& ebk) {
	ShowBookInfo((Book)ebk);
	cout << "DRM " << ebk.DRMKey << endl;
}

int main() {
	EBook eb1("C++", "5-1234-890-1", 10000, "fdx98dfx");

	ShowBookInfo(eb1);

//	EBook eb2 = eb1;

	EBook eb3("C#", "5-1234-890-2", 20000, "xfd89xdf");
	ShowBookInfo(eb3);
}
