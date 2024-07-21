#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // Start from the end of nums1 array
	int i = m + n - 1;

	// Decrease m and n to point to the last valid elements in nums1 and nums2
	--m;
	--n;

	// Merge nums1 and nums2 from the end to the beginning
	while (m >= 0 && n >= 0) {
		// Compare the elements from the end of nums1 and nums2
		if (nums1[m] < nums2[n]) {
			// Put the larger element from nums2 into nums1
			nums1[i] = nums2[n];
			--n; // Move to the previous element in nums2
		} else {
			// Put the larger element from nums1 into nums1
			nums1[i] = nums1[m];
			--m; // Move to the previous element in nums1
		}
		
		--i; // Move to the previous position in nums1
	}

	// If there are remaining elements in nums2, copy them to nums1
	while (n >= 0) {
		nums1[i] = nums2[n];
		--i;
		--n;
	}
}

int main(int argc, char* argv[]) {
	// Initialize nums1 and nums2 arrays
	vector<int> nums1 = {1,2,3,0,0,0,0}; // nums1 has extra space at the end
	vector<int> nums2 = {0,2,5,6};

	// Merge nums2 into nums1
	merge(nums1, 3, nums2, 4);

	// Print the merged array nums1
	cout << "[";
	for (int i = 0; i < nums1.size(); ++i)
		cout << nums1[i] << ((i != nums1.size()-1)? ", ":"");
	cout << "]" << endl;

	return 0;
}

