#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Book {
protected:
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

	Book(const Book &copy, const int price) {
		title = new char[strlen(copy.title) + 1];
		strcpy(title, copy.title);

		isbn = new char[strlen(copy.isbn) + 1];
		strcpy(isbn, copy.isbn);

		this->price = price;
	}

	void ShowBookInfo() {
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}

	~Book() {
		delete[] title;
		delete[] isbn;
	}
};

class EBook : public Book {
private:
	char* DRMKey;
public:
	EBook(const char* title, const char* isbn, const int price, const char* key) : Book(title, isbn, price) {
		DRMKey = new char[strlen(key) + 1];
		strcpy(DRMKey, key);
	}

	EBook(const Book& bk, const int price, const char* key) : Book(bk, price) {
		DRMKey = new char[strlen(key) + 1];
		strcpy(DRMKey, key);
	}

	void ShowBookInfo() {
		Book::ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}

	~EBook() {
		delete[] DRMKey;
	}
};


int main() {
	Book bk("C++ 프로그램", "555-12345-890-0", 20000);
	bk.ShowBookInfo();
	cout << endl;

	EBook ebk(bk, 10000, "fdx98dfx");
	ebk.ShowBookInfo();

	return 0;
}
