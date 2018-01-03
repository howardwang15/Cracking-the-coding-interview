#include <iostream>

using namespace std;

void replaceSpaces(string& array, int length) {
	int n_spaces = 0;
	for (int i = 0; i < length; ++i) {
		if (array[i] == ' ')
			n_spaces++;
	}

	int newLength = length + 2 * n_spaces;

	for (int i = length - 1; i >= 0; --i) {
		if (array[i] == ' ') {
			array[newLength - 3] = '%';
			array[newLength - 2] = '2';
			array[newLength - 1] = '0';
			newLength -= 3;
		}
		else {
			array[newLength - 1] = array[i];
			newLength--;
		}
	}
}

int main () {
	string s = "Mr John Smith    ";
	replaceSpaces(s, 13);
	for (int i = 0; i < s.length(); ++i) {
		cout << s[i];
	} 
	cout << endl;
}