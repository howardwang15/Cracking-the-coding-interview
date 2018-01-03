#include <iostream>
#include <cctype>

using namespace std;

bool isPalindrome(string s) {
	int array[256] = { 0 };
	for (int i = 0; i < s.length(); ++i) 
		s[i] = tolower(s[i]);
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == ' ') continue;
		int val = s[i];
		array[val]++;
	}

	int n_odd_letters = 0;
	for (int i = 0; i < 256; ++i) {
		if (array[i] % 2 != 0) 
			n_odd_letters++;
		if (n_odd_letters > 1) return false;
	}
	return true;
}

int main () {
	string s = "";
	cout << isPalindrome(s);
}