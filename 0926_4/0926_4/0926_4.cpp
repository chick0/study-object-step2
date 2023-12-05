#include <iostream>
using namespace std;

class Matrix {
private:
	int** mat;
	const int row;
	const int col;
public:
	Matrix(int _row, int _col) :
		row(_row), col(_col) {		
		mat = new int*[row];

		for (int i = 0; i < row; i++) {
			mat[i] = new int[col];
		}
	}

	~Matrix() {
		for (int i = 0; i < row; i++) {
			delete[] mat[i];
		}

		delete[] mat;
	}

	void Print() {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cout << mat[i][j] << "\t";
			}

			cout << "\n";
		}
	}

	void setRand() {
		srand((unsigned int)time(NULL));

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				mat[i][j] = rand() % 100;
			}
		}
	}
};

int main() {
	Matrix mt(10, 3);
	mt.setRand();
	mt.Print();

	return 0;
}
