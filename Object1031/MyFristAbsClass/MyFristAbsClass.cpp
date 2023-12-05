#include <iostream>
using namespace std;

class Vehicle {
protected:
    int speed;
public:
    Vehicle(const int speed) {
        this->speed = speed;
    }

    virtual void Show() = 0;
};

class Car : public Vehicle {
private:
    int num;
    double gas;
public:
    Car(const int num, const double gas, const int speed) : Vehicle(speed) {
        this->num = num;
        this->gas = gas;
    }

    virtual void Show() {
        cout << "> 자동차\n";
        cout << "번호: " << num << ", ";
        cout << "가솔린양: " << gas << ", ";
        cout << "속도: " << speed << endl;
    }
};

class Plane : public Vehicle {
private:
    int flight;
public:
    Plane(const int flight, const int speed) : Vehicle(speed) {
        this->flight = flight;
    }

    virtual void Show() {
        cout << "> 비행기\n";
        cout << "편명: " << flight << ", ";
        cout << "속도: " << speed << endl;
    }
};

int main()
{
    Vehicle* pv[2];
    Car c(8604, 25.5, 80);
    Plane p(940, 500);

    pv[0] = &c;
    pv[1] = &p;

    pv[0]->Show();
    pv[1]->Show();

    return 0;
}
