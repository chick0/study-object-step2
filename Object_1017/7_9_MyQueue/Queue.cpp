#include <iostream>
using namespace std;

class BaseArray {
private:
	int capacity;
	int* mem;
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity;
		mem = new int[capacity];
	}

	~BaseArray() {
		delete[] mem;
	}

	void Put(const int index, const int value) const {
		mem[index] = value;
	}

	int Get(const int index) const {
		return mem[index];
	}

	int GetCapacity() const {
		return capacity;
	}
};

class MyQueue : public BaseArray {
private:
	int index;
public:
	MyQueue(const int capacity) : BaseArray(capacity) {
		index = 0;
	}

	void Inqueue(int value) {
		if (index < GetCapacity()) {
			Put(index++, value);
		}
	}

	int Dequeue() {
		int tmp = Get(0);

		for (int i = 1; i <= index; i++) {
			Put(i - 1, Get(i));
		}

		index -= 1;

		return tmp;
	}

	int GetCapacity() const {
		return BaseArray::GetCapacity();
	}

	int GetLength() const {
		return index;
	}
};

int main() {
	MyQueue mq(100);

	for (int i = 0; i < 5; i++) {
		mq.Inqueue(i);
	}

	cout << "용량: " << mq.GetCapacity() << endl;
	cout << "크기: " << mq.GetLength() << endl;

	while (mq.GetLength() != 0) {
		cout << "Dequeue " << mq.Dequeue() << endl;
	}

	cout << "용량: " << mq.GetCapacity() << endl;
	cout << "크기: " << mq.GetLength() << endl;

	return 0;
}
