#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(string s) {

	int i = s.length() - 1;

	while (i >= 0 && s[i] == ' ')
		--i;

	if (i < 0)
		return 0;

	int length = 0;

	while (i >= 0 && s[i] != ' ') {
		--i;
		++length;
	}

	return length;
}

// Main function
int main(int argc, char* argv[]) {
	string str = "luffy is still joyboy";
	int length = lengthOfLastWord(str);
	cout << str << ": " << length << endl;
	return 0;
}
