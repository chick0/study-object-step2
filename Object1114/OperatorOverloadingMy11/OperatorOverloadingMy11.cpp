#include <iostream>
using namespace std;

class My {
private:
    int v;
public:
    My(int data) : v(data) {}

    void list() {
        cout << v << endl;
    }

    My& operator++() {
        v += 1;
        return *this;
    }

    const My& operator++(int) {
        const My ret(v);
        v += 1;

        return ret;
    }
};

int main()
{
    My a(5);
    My x = a++;

    a.list();
    x.list();

    My y = ++a;
    a.list();
    y.list();

    return 0;
}
