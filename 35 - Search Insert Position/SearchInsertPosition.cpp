#include <iostream>
#include <vector>

using namespace std;

// Used Binary Search Algorithm to solve the problem
// Time Complexity: O(N)
// Space Complexity: O(1)
int searchInsert(vector<int>& nums, int target) {

	int left = 0;
	int right = nums.size() - 1;

	while (left <= right) {
		int middle = left + (right - left) / 2;

		if (target > nums[middle])
			left = middle + 1;
		else if (target < nums[middle])
			right = middle - 1;
		else
			return middle;
	}

	return left;
}

void print(vector<int>& nums, bool newline = true) {
	for (int i = 0; i < nums.size(); ++i)
		cout << nums[i] << ((i != nums.size()-1)? ",":"");
	if (newline == true)
		cout << endl;
}

int main(int argc, char* argv[]) {
	vector<int> nums = {1, 3, 5, 6, 9};
	int target = 7;
	int index = searchInsert(nums, target);

	cout << "input: nums = [";
	print(nums, false);
	cout << "], target = " << target << endl;

	if (nums[index] != target) {
		cout << target << " not found" << endl;
		nums.insert(nums.begin()+index, target);
		cout << target << " inserted" << endl;
	} else {
		cout << target << " found" << endl;
	}

	cout << "input: nums = [";
	print(nums, false);
	cout << "], target = " << target << endl;

	return 0;
}
