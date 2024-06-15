#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
	unordered_set<int> known;
	for (int n: nums) {
		if (known.find(n) != known.end())
			return true;
		known.insert(n);
	}
	return false;
}

// Main function
int main(int argc, char* argv[]) {
	vector<int> arr = {1,2,3,4};
	cout << containsDuplicate(arr) << endl;
	return 0;
}
