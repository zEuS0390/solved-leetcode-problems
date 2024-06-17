#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
	if (nums.size() == 0) 
		throw runtime_error("The array must have at least one element.");

	int xor_result = 0;

	for (int num: nums)
		xor_result ^= num;

	return xor_result;
}

void print(vector<int> nums) {
	cout << "[";
	for (int i = 0; i < nums.size(); ++i)
		cout << nums[i] << ((i != nums.size()-1)? ',':'\0');
	cout << "]" << endl;
}

int main(int argc, char* argv[]) {
	vector<int> nums = {6,4,1,2,1,2,9,6,9};
	print(nums);
	int single_number = singleNumber(nums);
	cout << single_number << endl;
	return 0;
}
