#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Get the two numbers' indices in the array that add up to the target sum.
vector<int> twoSum(vector<int>& nums, int target) {

	// Store the known numbers along with their index of first occurrence.
	unordered_map<int, int> known;
	
	// Iterate through the array.
	for (int i = 0; i < nums.size(); ++i) {

		// Get the comlement of the current number relative to the target sum.
		int complement = target - nums[i];

		// Immediately return the indices if the complement is found in the unordered map (hash table).
		if (known.find(complement) != known.end())
			return {known[complement], i};

		// Store the current number in the unordered map (hash table)
		known[nums[i]] = i;
	}
	
	// Return empty when the process reaches at this point. 
	// It means that the numbers that add up to target sum do not exist.
	return {};
}

void print(vector<int>& nums){
	cout << "[";
	for (int i = 0; i < nums.size(); ++i)
		cout << nums[i] << ((i != nums.size()-1)? ",":"");
	cout << "]" << endl;
}

int main(int argc, char* argv[]) {
	vector<int> arr = {1,2,3,4,5,6,7,8,9};
	vector<int> result = twoSum(arr, 11);
	print(arr);
	print(result);
	return 0;
}
