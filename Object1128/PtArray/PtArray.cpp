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

    Point(const int x, const int y) {
        this->x = x;
        this->y = y;
    }

    void operator=(const Point copy){
        x = copy.x;
        y = copy.y;
    }

    friend ostream& operator<<(ostream&, const Point&);
};

ostream& operator<<(ostream& os, const Point& pt) {
    os << "(" << pt.x << ", " << pt.y << ")";
    return os;
}

class PointArray {
private:
    Point* arr;
    const int length;
public:
    PointArray(const int size) : length(size) {
        arr = new Point[length];
    }

    int Length() const {
        return length;
    }

    Point &operator[](const int index) {
        if (index < 0 || index >= length) {
            cout << "IndexError";
            exit(1);
        }

        return arr[index];
    }

    ~PointArray() {
        delete[] arr;
    }
};

int main()
{
    PointArray arr(3);
    arr[0] = Point(3, 4);
    arr[1] = Point(2, 8);
    arr[2] = Point(7, 5);

    for (int i = 0; i < arr.Length(); i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
