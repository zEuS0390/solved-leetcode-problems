#include <iostream>
#include <vector>

using namespace std;

void reverseString(vector<char>& s) {
	int left = 0;
	int right = s.size() - 1;

	while (left < right) {
		int tmp = s[right];
		s[right] = s[left];
		s[left] = tmp;
		++left;
		--right;
	}
}

void print(vector<char> s) {
	cout << "[";
	for (int i = 0; i < s.size(); ++i)
	cout << '"' << s[i] << '"' << ((i != s.size()-1)? ',':'\0');
	cout << "]" << endl;
}

int main(int argc, char* argv[]) {
	vector<char> str = {'h','e','l','l','o'};
	print(str);
	reverseString(str);
	print(str);
	return 0;
}
