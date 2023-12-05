#include <iostream>
using namespace std;

class Car {
protected:
    int num;
    double gas;
public:
    Car(const int n, const double g) {
        num = n;
        gas = g;
    }

    virtual void Show() {
        cout << "자동차의 번호: " << num << endl;
        cout << "자동차의 연료양: " << gas << endl;
    }
};

class RacingCar : public Car {
private:
    int course;

public:
    RacingCar(const int n, const double g, const int c) : Car(n, g) {
        course = c;
    }

    virtual void Show() {
        cout << "레이싱카의 번호: " << num << endl;
        cout << "레이싱카의 연료양: " << gas << endl;
        cout << "코스번호: " << course << endl;
    }
};

int main()
{
    Car* pCar[] = {
        new Car(4352, 35.5),
        new RacingCar(4344, 32.1, 3)
    };

    pCar[0]->Show(); cout << endl;
    pCar[1]->Show();

    delete pCar[0];
    delete pCar[1];
    
    return 0;
}
