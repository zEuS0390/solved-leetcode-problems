#include <iostream>
#include <vector>

using namespace std;

// Function to remove duplicates from a sorted array
int removeDuplicates(vector<int>& nums) {
    int k = 0; // Initialize a pointer 'k' for the position to store unique elements
  
    // Iterate through the array 'nums'
    for (int i = 0; i < nums.size(); ++i) {
        // Check if it's the first element or the current element is different from the previous one
        if (i == 0 || nums[i] != nums[i-1]) {
            nums[k] = nums[i]; // Store the current unique element at position 'k'
            k++; // Increment 'k' to point to the next position where the next unique element will be stored
        }
    }

    return k; // Return the count of unique elements
}

int main(int argc, char* argv[]) {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4}; // Example sorted array with duplicates
    int n = removeDuplicates(nums); // Call the function to remove duplicates and get the count of unique elements

    
    cout << "[";
    for (int i = 0; i < nums.size(); ++i)
        cout << nums[i] << ((i != nums.size()-1)? "," : "");
    cout << "]" << endl;

    // Output the modified array with only the first 'n' elements showing the unique elements
    cout << "[";
    for (int i = 0; i < nums.size(); ++i)
        cout << ((i < n)? to_string(nums[i]) : "_") << ((i != nums.size()-1)? "," : "");
    cout << "]" << endl;

    return 0;
}
