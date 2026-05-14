class Solution {
public:
    bool isGood(vector<int>& nums) {
        // Calculate n from the array size (array should have n+1 elements)
        int n = nums.size() - 1;
      
        // Initialize frequency array to count occurrences of each number
        // Size 201 to handle numbers up to 200
        int frequency[201] = {};
      
        // Count frequency of each number in the input array
        for (int number : nums) {
            ++frequency[number];
        }
      
        // Check if the largest number n appears exactly twice
        if (frequency[n] != 2) {
            return false;
        }
      
        // Check if all numbers from 1 to n-1 appear exactly once
        for (int i = 1; i < n; ++i) {
            if (frequency[i] != 1) {
                return false;
            }
        }
      
        // All conditions satisfied - array is "good"
        return true;
    }
};
