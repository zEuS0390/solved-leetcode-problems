#include <iostream>
#include <string>

using namespace std;

// This is the brute force (naive) algorithm to find the pattern in a string through linear searching.
// Time Complexity: O(N * M)
// Space Complexity: O(1)
int strStr(string haystack, string needle) {
	int haystack_len = haystack.size();
	int needle_len = needle.size();
	for (int i = 0; i < haystack_len - needle_len + 1; ++i) {
		int n = 0; 
		while (n < needle_len) {
			if (needle[n] != haystack[i + n]) break;
			++n;
		}
		if (n == needle_len) return i;
	}
	return -1;
}

// Others:
// - Knuth-Morris-Pratt Algorithm O(N+M)
// - Boyer-Moore Algorithm

// Main function
int main(int argc, char* argv[]) {
	int index = strStr("hero jae baltazar", "jae");
	cout << ((index >= 0)? to_string(index) : "not found") << endl;
	return 0;
}
