class Solution {
public:
    int minimumOperations(vector<int>& nums)
    {
        vector<int> temp(101, 0); // Array to track occurrences of elements
        int last_index = 0;

        // Traverse from right to left to find duplicates
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (temp[nums[i]] > 0) { // Duplicate found
                last_index = i + 1; // Update the last index
                break;
            }
            temp[nums[i]]++; // Mark the element as seen
        }

        // Calculate the number of operations
        if (last_index % 3 == 0) {
            return last_index / 3;
        } else {
            return last_index / 3 + 1;
        }
    }
};