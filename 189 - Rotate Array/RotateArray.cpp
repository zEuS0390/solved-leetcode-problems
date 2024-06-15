#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& nums) {
	cout << "[";
	for (int i = 0; i < nums.size(); ++i)
		cout << nums[i] << ((i != nums.size()-1)? ", ":"");
	cout << "]" << endl;
}

void swap(int& num1, int& num2) {
	int temp = num2;
	num2 = num1;
	num1 = temp;
}

void reverse(vector<int>& nums, int left, int right) {
	while (left < right)
		swap(nums[left++], nums[right--]);
}

void rotateArray(vector<int>& nums, int k) {
	k = k % nums.size();
	reverse(nums, 0, nums.size()-1);
	reverse(nums, 0, k-1);
	reverse(nums, k, nums.size()-1);
}

int main(int argc, char* argv[]) {
	vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	rotateArray(arr, 8);
	print(arr);
	return 0;
}
