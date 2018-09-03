#include <iostream>

using namespace std;

bool isUnique(string s) {
	int frequencies[256] = { 0 };
	for (char c: s) {
		int val = c;
		if (frequencies[val] != 0) return false;
		frequencies[val]++;
	}
	return true;
}

int main () {

}