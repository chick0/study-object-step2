#include <iostream>
using namespace std;

class Point {
private:
    int x;
    int y;
public:
    Point() {
        x = 0;
        y = 0;
    }

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    friend void ShowPosition(const Point& ro);
    friend Point& operator++(Point& ref);
    friend const Point operator++(Point& ref, int);
    friend Point& operator--(Point& ref);
    friend const Point operator--(Point& ref, int);
};

void ShowPosition(const Point& ro) {
    cout << "(" << ro.x << ", " << ro.y << ")" << endl;
}

Point& operator++(Point& ref) {
    ref.x += 1;
    ref.y += 1;

    return ref;
}

const Point operator++(Point& ref, int) {
    const Point ret(ref);
    ref.x += 1;
    ref.y += 1;

    return ret;
}

Point& operator--(Point& ref) {
    ref.x -= 1;
    ref.y -= 1;

    return ref;
}

const Point operator--(Point& ref, int) {
    const Point ret(ref);
    ref.x -= 1;
    ref.y -= 1;

    return ret;
}

int main()
{
    Point pos(20, 30);

    cout << "------- 후위 증가 -------\n";
    ShowPosition(pos++);
    ShowPosition(pos);

    cout << "------- 전위 증가 -------\n";
    ShowPosition(++pos);
    ShowPosition(pos);

    cout << "------- 후위 감소 -------\n";
    ShowPosition(pos--);
    ShowPosition(pos);

    cout << "------- 전위 감소 -------\n";
    ShowPosition(--pos);
    ShowPosition(pos);

    return 0;
}
