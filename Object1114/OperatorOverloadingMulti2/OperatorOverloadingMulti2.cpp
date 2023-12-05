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
    friend Point operator*(const Point& a, const int& b);
    friend Point operator*(const int& a, const Point& b);
};

void ShowPosition(const Point& ro) {
    cout << "(" << ro.x << ", " << ro.y << ")" << endl;
}

Point operator*(const Point& a, const int& b) {
    return Point(a.x * b, a.y * b);
}

Point operator*(const int& a, const Point& b) {
    return Point(a * b.x, a * b.y);
}

int main()
{
    Point pos(20, 30);
    Point result;

    result = 3 * pos;
    ShowPosition(result);
    
    result = 2 * pos * 3;
    ShowPosition(result);

    return 0;
}
