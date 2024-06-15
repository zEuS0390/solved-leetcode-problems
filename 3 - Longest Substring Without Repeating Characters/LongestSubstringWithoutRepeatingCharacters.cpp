#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

// Time Complexity: O(N)
// Space Complexity: O(min(N, M)) where N is the length of the input string 's', and m is the size of the character set (in the worst case, all characters are unique)
int lengthOfLongestSubstring(string s) {
	int left = 0;
	int right = 0;
	int max_len = 0;

	unordered_set<char> chars;

	while (right < s.length()) {
		if (chars.find(s[right]) == chars.end()) {
			chars.insert(s[right]);
			++right;
			max_len = max(max_len, right - left);
		} else {
			chars.erase(s[left]);
			++left;
		}

	}

	return max_len;
}

int main(int argc, char* argv[]) {
	int length = lengthOfLongestSubstring("pwwkew");
	cout << length << endl;
	return 0;
}
