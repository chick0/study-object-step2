#include <iostream>
using namespace std;

class Point {
private:
    int x;
    int y;
public:
    Point(int X, int Y): x(X), y(Y) {}

    Point operator-(const Point& ref) {
        return Point(x - ref.x, y - ref.y);
    }

    Point operator+(const Point& ref) {
        return Point(x + ref.x, y + ref.y);
    }

    void Show() {
        cout << x << ", " << y << endl;
    }
};

int main()
{
    Point a(3, 4);
    Point b(20, 15);

    Point c = b - a;
    c.Show();

    Point d = a + b;
    d.Show();


    return 0;
}
