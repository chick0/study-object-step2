#include <iostream>
using namespace std;

class Error {
private:
    const int eid;
    const string msg;
public:
    Error(const int code, const string message) : eid(code), msg(message) {}

    int GetErrorCode() const {
        return eid;
    }

    string GetMessage() const {
        return msg;
    }

    void Print() const {
        cout << eid << ": " << msg;
    }
};

class Point {
private:
    int x;
    int y;
public:
    Point() {
        x = 0;
        y = 0;
    }

    void Set(const int x, const int y) {
        if (x <= 0) {
            throw Error(0xff00, "x좌표는 음수일 수 없습니다.");
        }
        else if (y <= 0) {
            throw Error(0xff00, "y좌표는 음수일 수 없습니다.");
        }

        this->x = x;
        this->y = y;
    }
};

int main()
{
    Point *p = new Point();
    int x, y;
    cin >> x >> y;

    try {
        p->Set(x, y);
    }
    catch (Error ex) {
        ex.Print();
    }

    delete p;
    return 0;
}
