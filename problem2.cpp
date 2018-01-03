#include <iostream>

using namespace std;

bool isPermutation(string s1, string s2) {
	if (s1.length() != s2.length()) return false;
	int frequencies[256] = { 0 };
	for (int i = 0; i < s1.length(); ++i) {
		int value = s1[i];
		frequencies[value]++;
	}

	for (int i = 0; i < s2.length(); ++i) {
		int value = s2[i];
		frequencies[value]--;
	}

	for (int i = 0; i < 256; ++i) { 
		if (frequencies[i] != 0) 
			return false;
	}
		
	
	return true;
}

int main () {
	string s1 = "hello", s2 = "lloer";
	cout << isPermutation(s1, s2);
}