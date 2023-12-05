#include <iostream>
using namespace std;

template <class T>
void SwapData(T &a, T &b) {
    T c;

    c = a;
    a = b;
    b = c;
}


int main()
{
    int x = 3;
    int y = 10;

    SwapData<int>(x, y);
    cout << x << ", " << y << endl;

    //////////////////////////

    float fx = 10.3;
    float fy = 21.3;

    SwapData<float>(fx, fy);
    cout << fx << ", " << fy << endl;
    
    //////////////////////////

    char cx = 'A';
    char cy = 'Z';

    SwapData<char>(cx, cy);
    cout << cx << ", " << cy << endl;

    return 0;
}
