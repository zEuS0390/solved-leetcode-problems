#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>

namespace first {
    // Function to check if two strings are anagrams using unordered_map
    bool isAnagram(std::string s, std::string t) {
        // Check if lengths of s and t are different, they cannot be anagrams
        if (s.length() != t.length())
            return false;

        // Count occurrences of each character in s and t
        std::unordered_map<char, int> s_count;
        std::unordered_map<char, int> t_count;

        // Count characters in string s
        for (int i = 0; i < s.length(); ++i) {
            s_count[s[i]]++;
        }

        // Count characters in string t
        for (int i = 0; i < t.length(); ++i) {
            t_count[t[i]]++;
        }

        // Compare counts of each character in s and t
        for (const char& c : s) {
            if (s_count[c] != t_count[c])
                return false;
        }

        // If all characters and their counts match, strings are anagrams
        return true;
    }
}

namespace second {
    // Function to check if two strings are anagrams using sorting
    bool isAnagram(std::string s, std::string t) {
        // Sort characters in both strings
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        // Compare sorted strings
        return s == t;
    }
}

// Main function
int main(int argc, char* argv[]) {
    {
        // Test case using first namespace (unordered_map approach)
        bool result = first::isAnagram("anagram", "gramaan");
        std::cout << result << std::endl;  // Output: 1 (true) because "anagram" and "gramaan" are anagrams
    }
    {
        // Test case using second namespace (sorting approach)
        bool result = second::isAnagram("rat", "car");
        std::cout << result << std::endl;  // Output: 0 (false) because "rat" and "car" are not anagrams
    }
    return 0;
}
