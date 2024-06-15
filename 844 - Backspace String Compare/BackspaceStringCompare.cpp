#include <iostream>
#include <string>

using namespace std;

// Time Complexity: O(n + m) where 'n' is the size of the s and 'm' is the size of the t 
// Space Complexity: O(1) as only a few extra variables are used, and no additional space proportional to the input size required
bool backspaceCompare(string s, string t) {

	auto getNextValidChar = [](string str, int& str_ptr) {
		int backspaces = 0;
		while (str_ptr >= 0 && (str[str_ptr] == '#' || backspaces > 0)) {
			if (str[str_ptr] == '#')
				++backspaces;
			else
				--backspaces;
			--str_ptr;
		}
	};

	int s_pointer = s.length() - 1;
	int t_pointer = t.length() - 1;
	
	while (s_pointer >= 0 || t_pointer >= 0) {

		getNextValidChar(s, s_pointer);
		getNextValidChar(t, t_pointer);

		if (s_pointer >= 0 && t_pointer >= 0 && s[s_pointer] != t[t_pointer])
			return false;

		if (s_pointer >= 0 != t_pointer >= 0)
			return false;

		--s_pointer;
		--t_pointer;
	}

	return true;
}


int main(int argc, char* argv[]) {

	auto trueOrFalse = [](bool val) {
		return val? "true" : "false";
	};

	// All of them are correct
	cout << trueOrFalse(backspaceCompare("ab#c", "ad#c")) << endl;
	cout << trueOrFalse(backspaceCompare("ab##", "c#d#")) << endl;
	cout << trueOrFalse(backspaceCompare("a#c", "b")) << endl; 
	cout << trueOrFalse(backspaceCompare("ab#ycd#", "ab#ycd#")) << endl;

	return 0;
}
