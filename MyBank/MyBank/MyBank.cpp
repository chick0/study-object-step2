#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

#define MAX_CLIENT 100

using namespace std;

struct AccountBaseInfo {
	int accId;
	char* name;
};

class Account {
private:
	int accID;
	string regID;
	char* name;
	int balance;
public:
	Account() {
		accID = rand() % INT_MAX;
		regID = "-";
		name = new char[0];
		balance = 0;
	}

	Account(const Account& copy) {
		accID = copy.accID;
		regID = copy.regID;
		SetName(copy.name);
		balance = copy.balance;
	}

	const char* GetName() {
		return name;
	}

	void SetAccId(const int &accID) {
		this->accID = accID;
	}

	void setRegID(const string &regID) {
		this->regID = regID;
	}

	void SetName(const char* newName) {
		delete[] name;
		name = new char[strlen(newName) + 1];
		strcpy(name, newName);
	}

	void SetName(const string newName) {
		delete[] name;
		name = new char[newName.length() + 1];

		for (int i = 0; i < newName.length(); i++) {
			name[i] = newName[i];
		}

		name[newName.length() + 1] = '\0';
	}

	void SetBalance(const int &balace) {
		this->balance = balance;
	}

	int GetBalance() const {
		return balance;
	}

	void GetBaseInfo(AccountBaseInfo& bi) const {
		bi.accId = accID;
		bi.name = name;
	}

	void Deposit(const int &money) {
		balance += money;
	}

	bool Withdraw(const int &money) {
		if (balance >= money) {
			balance -= money;
			return true;
		}
		else {
			return false;
		}
	}

	~Account() {
		delete[] name;
	}
};

class Bank {
private:
	Account* accounts[MAX_CLIENT];
	int counter;
public:
	Bank() {
		counter = 0;
	}

	int GetCounter() const {
		return counter;
	}

	Account *NewAccount(const string& regID, const char* name) {
		accounts[counter] = new Account();
		accounts[counter]->setRegID(regID);
		accounts[counter]->SetName(name);

		return accounts[counter++];
	}

	Account* GetAccount(const int& index) const {
		return accounts[index];
	}

	void GetAccountBaseInfo(const int& index, AccountBaseInfo& bi) const {
		accounts[index]->GetBaseInfo(bi);
	}

	Account* SearchAccount(int accID) const {
		AccountBaseInfo bi;

		for (int i = 0; i < counter; i++) {
			GetAccountBaseInfo(i, bi);

			if (bi.accId == accID) {
				return accounts[i];
			}
		}

		return nullptr;
	}

	~Bank() {
		for (int i = 0; i < counter; i++) {
			delete (accounts + i);
		}
	}
};

void printMenu(string &menu) {
	cout << "[1]: 계좌 개설" << endl;
	cout << "[2]: 입     금" << endl;
	cout << "[3]: 출     금" << endl;
	cout << "[4]: 전체고객 잔액 조회" << endl;
	cout << "=============================" << endl;
	cout << "메뉴 선택: ";
	cin >> menu;
}

void ShowBaseInfo(const Account* ac) {
	AccountBaseInfo bi;
	ac->GetBaseInfo(bi);

	cout << bi.name << "님의 계좌("<< bi.accId << ") 잔액은 " << ac->GetBalance() << "원 입니다." << endl;
}

int main()
{
	srand((unsigned)time(NULL));
	Bank bank;

	while (true) {
		string menu; printMenu(menu);

		if (menu == "1") {
			string regID;
			string name;

			cout << "주민등록번호를 입력해주세요. : ";
			cin >> regID;

			cout << "이름을 입력해주세요. : ";
			getline(cin >> ws, name);

			ShowBaseInfo(bank.NewAccount(regID, name.c_str()));
		}
		else if (menu == "2") {
			int accID;
			int money;

			cout << "계좌 번호를 입력해주세요. : ";
			cin >> accID;

			Account* ac = bank.SearchAccount(accID);


			if (ac == nullptr) {
				cout << "등록된 계좌가 아닙니다." << endl;
				continue;
			}

			cout << "입금 금액을 입력해주세요. : ";
			cin >> money;

			ac->Deposit(money);
			ShowBaseInfo(ac);
		}
		else if (menu == "3") {
			int accID;
			int money;

			cout << "계좌 번호를 입력해주세요. : ";
			cin >> accID;

			Account* ac = bank.SearchAccount(accID);

			if (ac == nullptr) {
				cout << "등록된 계좌가 아닙니다." << endl;
				continue;
			}

			cout << "출금 금액을 입력해주세요. : ";
			cin >> money;

			if (ac->Withdraw(money)) {
				ShowBaseInfo(ac);
			}
			else {
				cout << "잔액이 부족합니다. (" << ac->GetBalance() << ")" << endl;
				continue;
			}
		}
		else if (menu == "4") {
			for (int i = 0; i < bank.GetCounter(); i++) {
				ShowBaseInfo(bank.GetAccount(i));
			}
		}
	}

	return 0;
}
