#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

int firstUniqueChar(string s) {

	unordered_map<char, int> chars;

	for (char c: s)
		chars[c]++;

	for (int i = 0; i < s.size(); ++i) {
		if (chars[s[i]] == 1)
			return i;
	}

	return -1;
}

int main(int argc, char* argv[]) {
	string str = "leetcode";
	int index = firstUniqueChar(str);
	cout << index << endl;
	return 0;
}
