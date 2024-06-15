#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {

	int maximum_subarray_sum = nums[0];
	int current_sum = 0;

	for (int i = 0; i < nums.size(); ++i) {
		if (current_sum < 0)
			current_sum = 0;
		current_sum += nums[i];
		maximum_subarray_sum = max(current_sum, maximum_subarray_sum);
	}

	return maximum_subarray_sum;
}

int main(int argc, char* argv[]) {
	vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
	int answer = maxSubArray(arr);
	cout << "ANSWER: " << answer << endl;
	return 0;
}
