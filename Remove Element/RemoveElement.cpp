#include <iostream>
#include <vector>
#include <string>

using namespace std;

int removeElement(vector<int>& nums, int val) {

	// The position that will be used to store the current index that is not equal to val
	int k = 0;

	// Iterate through the array
	for (int i = 0; i < nums.size(); ++i) {

		if (nums[i] != val) {
			// If the current value 'nums[i]' is not equal to the val, then set the current value in position 'k'
			nums[k] = nums[i];

			// Increment the 'k' for the next position to be set
			k++;
		}
	}

	// Return the 'k' which is the number of elements that are not equal to val
	return k;
}

int main(int argc, char* argv[]) {
	vector<int> nums = {0,1,2,2,3,0,4,2};
	int val = 2;
	int n = removeElement(nums, val); 

	cout << "[";
	for (int i = 0; i < nums.size(); ++i)
		cout << ((i < n)? to_string(nums[i]):"_") << ((i != nums.size()-1)? ",":"");
	cout << "]" << endl;

	return 0;
}
