#include <iostream>
using namespace std;

class Point {
private:
    const int x;
    const int y;
public:
    Point(int _x, int _y):
        x(_x), y(_y) {}

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }
};

void ShowPoint(const Point* p) {
    cout << "(" << p->getX() << ", " << p->getY() << ")" << endl;
}

int main()
{
    Point ps[] = { {10, 10}, {20, 20}, {30, 30} };
    Point* ptr = ps;

    for (int i = 0; i < sizeof(ps) / sizeof(Point); i++) {
        ShowPoint((ptr + i));
    }

    return 0;
}
