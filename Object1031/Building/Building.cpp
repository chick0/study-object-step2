#include <iostream>
using namespace std;

class Building {
protected:
    int pyeong;
    string address;
public:
    Building(const int p, const string addr) {
        pyeong = p;
        address = addr;
    }

    virtual void Show() {
        cout << "건물(" << address << ") " << pyeong << "평" << endl;
    }
};

class House : public Building {
private:
    int numrooms;
    int cost;
public:
    House(const int p, const string addr, const int room, const int cost) : Building(p, addr) {
        numrooms = room;
        this->cost = cost;
    }

    virtual void Meow() = 0;

    virtual void Show() {
        cout << "집(" << address << ") " << pyeong << "평, 방 " << numrooms << "개, 가격 " << cost << "원" << endl;
    }
};

class Office : public Building {
private:
    string zoneCode;
    int rent;
public:
    Office(const int p, const string addr, const string zone, const int rent) : Building(p, addr) {
        zoneCode = zone;
        this->rent = rent;
    }

    virtual void Show() {
        cout << "사무실(" << address << ") " << pyeong << "평, 우편번호 " << zoneCode << ", 전세금 " << rent << "원" << endl;
    }
};

int main()
{
    Building* ptr[] = {
        new House(32, "경기도 부천시 원미구", 4, 350000),
        new Office(24, "서울 종로구", "110-400", 30000),
        new Office(24, "인천 서구", "405-222", 1000),
    };

    for (int i = 0; i < sizeof(ptr) / sizeof(Building*); i++)
        ptr[i]->Show();

    for (int i = 0; i < sizeof(ptr) / sizeof(Building*); i++)
        delete ptr[i];
}
