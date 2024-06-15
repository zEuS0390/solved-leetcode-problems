#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

	int i = m + n - 1;

	--m;
	--n;

	while (m >= 0 && n >= 0) {

		if (nums1[m] < nums2[n]) {
			nums1[i] = nums2[n];
			--n;
		} else {
			nums1[i] = nums1[m];
			--m;
		}
		
		--i;
	}

	while (n >= 0) {
		nums1[i] = nums2[n];
		--i;
		--n;
	}
}

int main(int argc, char* argv[]) {
	vector<int> nums1 = {1,2,3,0,0,0,0};
	vector<int> nums2 = {0,2,5,6};
	merge(nums1, 3, nums2, 4);

	cout << "[";
	for (int i = 0; i < nums1.size(); ++i)
		cout << nums1[i] << ((i != nums1.size()-1)? ", ":"");
	cout << "]" << endl;
	return 0;
}
