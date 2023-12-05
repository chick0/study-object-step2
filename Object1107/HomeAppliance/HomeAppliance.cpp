#include <iostream>

using namespace std;

class HomeAppliance{
protected:
	string model;
	int price;
	string color;

	void ShowBaseInfo() const {
		cout << "모델\t" << model << endl;
		cout << "가격\t" << price << endl;
		cout << "색상\t" << color << endl;
	}
public:
	HomeAppliance(string model, int price, string color) {
		this->model = model;
		this->price = price;
		this->color = color;
	}

	virtual void Show() const = 0;
	virtual ~HomeAppliance() {}
};

class Refrigerator : public HomeAppliance {
private:
	int Volume;
public:
	Refrigerator(string model, int price, string color, int volume) : HomeAppliance(model, price, color) {
		this->Volume = volume;
	}

	void Show() const {
		cout << "> 냉장고" << endl;
		HomeAppliance::ShowBaseInfo();
		cout << "용량\t" << Volume;
	}

	virtual ~Refrigerator() {}
};

class Washer : public HomeAppliance {
private:
	float Volume;
public:
	Washer(string model, int price, string color, float volume) : HomeAppliance(model, price, color) {
		this->Volume = volume;
	}

	virtual void Show() const {
		cout << "> 세탁기" << endl;
		HomeAppliance::ShowBaseInfo();
		cout << "용량\t" << Volume;
	}

	virtual ~Washer() {}
};

class Humidifier : public HomeAppliance {
private:
	bool isAuto;
public:
	Humidifier(string model, int price, string color, bool isAuto) : HomeAppliance(model, price, color) {
		this->isAuto = isAuto;
	}

	virtual void Show() const {
		cout << "> 가습기" << endl;
		HomeAppliance::ShowBaseInfo();
		cout << "자동\t" << isAuto;
	}

	virtual ~Humidifier(){}
};

int main()
{
	HomeAppliance* items[] = {
		new Refrigerator("냉장고", 35000, "#FFCC4D", 1000),
		new Washer("세탁기", 10000, "#FFFFFF", 50),
		new Refrigerator("가습기", 100000, "#99FFC8", 1000),
	};

	for (int i = 0; i < sizeof(items) / sizeof(HomeAppliance*); i++) {
		items[i]->Show();
		cout << "\n\n";

		delete items[i];
	}
}
