#include <iostream>
using namespace std;

class Point {
private:
    int x;
    int y;
public:
    Point(int X, int Y) : x(X), y(Y) {}

    void Show() {
        cout << x << ", " << y << endl;
    }

    friend Point operator-(const Point& a, const Point& b);
    friend bool operator==(const Point& a, const Point& b);
    friend bool operator!=(const Point& a, const Point& b);
};

Point operator-(const Point& a, const Point& b) {
    return Point(a.x - b.x, a.y - b.y);
}

bool operator==(const Point& a, const Point& b) {
    return (a.x == b.x) && (a.y == b.y);
}

bool operator!=(const Point& a, const Point& b) {
    return (a.x != b.x) || (a.y != b.y);
}

int main()
{
    Point pos1(3, 4);
    Point pos2(10, 20);

    Point pos3 = pos2 - pos1;
    pos3.Show();

    bool isSame = pos1 == pos2;
    cout << isSame << endl;

    bool isNotSame = pos1 != pos2;
    cout << isNotSame << endl;

    return 0;
}

