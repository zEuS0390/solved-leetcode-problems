#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Time Complexity: O(N)
// Space Complexity: O(N) due to the additional space used for vector
int rob(vector<int>& nums) {
	if (nums.empty()) return 0;
	if (nums.size() == 1) return nums[0];

	vector<int> dP(nums.size());

	dP[0] = nums[0];
	dP[1] = max(nums[0], nums[1]);

	for (int i = 2; i < nums.size(); ++i)
		dP[i] = max(nums[i] + dP[i - 2], dP[i - 1]);

	for (int i = 0; i < dP.size(); ++i)
		cout << dP[i] << ((i != dP.size()-1)? ", ": "");
	cout << endl;

	return dP.back();
}

// Time Complexity: O(N)
// Space Complexity: O(1)
int robOptimized(vector<int>& nums) {
	if (nums.empty()) return 0;
	if (nums.size() == 1) return nums[0];

	int prev1 = nums[0];
	int prev2 = max(nums[0], nums[1]);

	for (int i = 2; i < nums.size(); ++i){
		int current = max(nums[i] + prev1, prev2);
		prev1 = prev2;
		prev2 = current;
	}

	return prev2;
}

int main(int argc, char* argv[]) {
	vector<int> arr = {2, 7, 9, 3, 1};
	int result = rob(arr);
	cout << result << endl;
	return 0;
}
