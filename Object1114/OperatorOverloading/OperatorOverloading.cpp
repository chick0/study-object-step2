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

    Point(const Point& copy) {
        x = copy.x;
        y = copy.y;
    }

    Point operator* (const int& target) {
        return Point(x * target, y * target);
    }

    friend void ShowPosition(const Point& ro);
};

void ShowPosition(const Point &ro) {
    cout << "(" << ro.x << ", " << ro.y << ")" << endl;
}

int main()
{
    Point pos(1, 2);
    Point result;

    result = pos * 3;
    ShowPosition(result);

    result = pos * 3 * 2;
    ShowPosition(result);

    return 0;
}
