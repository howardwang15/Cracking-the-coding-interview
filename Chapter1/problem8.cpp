#include <iostream>
#include <vector>

using namespace std;

const int M = 5;
const int N = 5;

void nullify(int array[][N]) {
	vector<int> zeroes;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			if (array[i][j] == 0) {
				zeroes.push_back(i);
				zeroes.push_back(j);
			}
		}
	}
	while (!zeroes.empty()) {
		for (int i = 0; i < N; ++i) {
			array[zeroes[0]][i] = 0;
		}
		for (int i = 0; i < M; ++i) {
			array[i][zeroes[1]] = 0;
		}
		zeroes.erase(zeroes.begin());
		zeroes.erase(zeroes.begin());
	}
}

void display(int array[][N]) {
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) 
			cout << array[i][j];
		cout << endl;
	}
}

int main () {
	int array[M][N];
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j)
			array[i][j] = i + j;
	}

	array[M - 1][N - 1] = 0;
	nullify(array);
	display(array);
}