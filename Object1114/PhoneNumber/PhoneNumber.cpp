#define _CRT_NO_SECURE_WARNINGS
#include <iostream>
using namespace std;

class PhoneNumber {
private:
    char area[4];
    char exchange[5];
    char line[5];
public:
    friend ostream& operator<<(ostream&, const PhoneNumber&);
    friend istream& operator>>(istream&, PhoneNumber&);
};

ostream& operator<<(ostream& out, const PhoneNumber& pn) {
    out << pn.area << "-" << pn.exchange << "-" << pn.line;
    return out;
}

istream& operator>>(istream& in, PhoneNumber& pn) {
    in >> pn.area;
    in >> pn.exchange;
    in >> pn.line;

    return in;
}



int main()
{
    PhoneNumber pn;
    cin >> pn;
    cout << pn;

    return 0;
}
