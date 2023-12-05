#include <iostream>

using namespace std;

class Array {
private:
    int* arr;
    int length;
public:
    Array(int length){
        this->length = length;
        arr = new int[length];
        memset(arr, 0, sizeof(int) * length);
    }

    int &operator[] (int index) {
        if (index >= 0 && index < length) {
            return arr[index];
        }

        cout << "ArrayIndexException";
        exit(1);
    }

    ~Array() {
        delete[] arr;
    }
};


int main()
{
    Array arr(10);

    for (int i = 0; i < 10; i++) {
        arr[i] = i;
        cout << arr[i] << endl;
    }

    return 0;
}
