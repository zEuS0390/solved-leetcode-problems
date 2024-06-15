#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& nums) {
	cout << "[";
	for (int i = 0; i < nums.size(); ++i)
		cout << nums[i] << ((i != nums.size()-1)? ", ": "");
	cout << "]" << endl;
}

// Time Complexity: O(N)
// Space Complexity: O(1)
void moveZeroes(vector<int>& nums) {
	int non_zero_pos = 0;

	cout << "Move all non-zero elements in the front of the array:" << endl;
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] != 0)
			nums[non_zero_pos++] = nums[i];
		cout << "i: " << i << "; non_zero_pos: " << non_zero_pos << "; array: ";
		print(nums);
	}
	cout << endl;

	cout << "Fill the remaining elements with zeroes:" << endl;
	for (int i = non_zero_pos; i < nums.size(); ++i) {
		nums[i] = 0;
		print(nums);
	}

}

int main(int argc, char* argv[]) {
	vector<int> arr = {0, 1, 0, 3, 12, 0, 99, 124, 0, 132};
	moveZeroes(arr);
	return 0;
}
