class Solution {
public:
    // Function to determine if the input array can be partitioned into two subsets of equal sum
    bool canPartition(vector<int>& nums) {
        // Calculate the sum of elements in the nums array
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // If the total sum is odd, it's not possible to divide it into two equal parts
        if (totalSum % 2 == 1) {
            return false;
        }

        // Target sum for each partition
        int targetSum = totalSum >> 1;

        // Create a dynamic programming array to keep track of possible sums
        bool dp[targetSum + 1];

        // Initialize the dynamic programming array to false
        memset(dp, false, sizeof(dp));

        // The sum of 0 is always achievable (by selecting no elements)
        dp[0] = true;

        // Iterate through the numbers in the array
        for (int num : nums) {
            // Check each possible sum in reverse to avoid using a number twice
            for (int j = targetSum; j >= num; --j) {
                // Update the dp array: dp[j] will be true if dp[j - num] was true
                // This means that current number 'num' can add up to 'j' using the previous numbers
                dp[j] = dp[j] || dp[j - num];
            }
        }

        // The result is whether it's possible to achieve the targetSum using the array elements
        return dp[targetSum];
    }
};