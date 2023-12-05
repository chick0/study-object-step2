#include <iostream>
using namespace std;

template <class T>
void sort(T arr[], const int length) {
	T tmp;

	for (int i = 0; i < length - 1; i++) {
		for (int j = i + 1; j < length; j++) {
			if (arr[i] > arr[j]) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

int main() {
	int var[] = { 3,5,1,9,4 };
	char str[] = "gasgdargc";

	sort(str, strlen(str));

	for (int i = 0; i < strlen(str); i++) {
		cout << str[i] << " ";
	}

	cout << "\n~~~~~~~~~~~~\n";

	sort(var, sizeof(var) / sizeof(int));

	for (int i = 0; i < sizeof(var) / sizeof(int); i++) {
		cout << var[i] << " ";
	}

	return 0;
}