#include <iostream>
using namespace std;

template <class T>
class Info {
private:
    T data;
public:
    void getData() {
        cin >> data;
    }

    void showData() {
        cout << data << endl;
    }
};

int main()
{
    Info <int> i;
    Info <double> d;
    Info <char> ch;

    cout << "정수: ";
    i.getData();

    cout << "실수: ";
    d.getData();

    cout << "문자: ";
    ch.getData();

    cout << "~~~~~~~~~~~~~~~~\n";
    i.showData();
    d.showData();
    ch.showData();

    return 0;
}
