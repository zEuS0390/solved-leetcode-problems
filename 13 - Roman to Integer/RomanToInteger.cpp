#include <unordered_map>
#include <iostream>

using namespace std;

int romanToInt(string s) {
	unordered_map<char, int> roman_numerals = {
		{'I', 1},
		{'V', 5},
		{'X', 10},
		{'L', 50},
		{'C', 100},
		{'D', 500},
		{'M', 1000}
	};

	int result = 0;
	int lastValue = 0;
	for (int i = s.length()-1; i >= 0; --i) {
		int value = roman_numerals[s[i]];

		if (value < lastValue)
			result -= value;
		else
			result += value;

		lastValue = value;
	}

	return result;
}

int main(int argc, char* argv[]) {
	int result = romanToInt("MMXXIV");
	cout << result << endl;
	return 0;
}
