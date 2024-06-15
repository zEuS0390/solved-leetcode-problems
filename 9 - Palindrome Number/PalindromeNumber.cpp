#include <iostream>

using namespace std;

bool isPalindrome(int x) {

	if (x < 0) return false;

	int div = 1;

	while (x >= div * 10) {
		div *= 10;
	}

	while (x != 0) {

		int left = x / div;
		int right = x % 10;

		if (left != right) return false;

		x = (x % div) / 10;
		div /= 100;
	}

	return true;
}

int main(int argc, char* argv[]) {
	int number = 13313;
	cout << "Is '" << number << "' a palindrome number?: " << (isPalindrome(number)? "yes":"no") << endl;
	return 0;
}
