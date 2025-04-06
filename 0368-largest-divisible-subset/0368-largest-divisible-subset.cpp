class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // Step 1: Sort the input array in ascending order.
        // Sorting helps in simplifying the divisibility checks because 
        // for any two numbers a and b, if a divides b and a < b,  
        // we only need to check the previous smaller numbers.
        sort(nums.begin(), nums.end());

        int n = nums.size();  // Get the size of the input array
        vector<int> dp(n, 1);  // dp[i] will store the size of the largest divisible subset ending at index i
        vector<int> prev(n, -1);  // prev[i] will store the index of the previous element in the subset for backtracking
        
        int maxIndex = 0;  // This will store the index of the last element in the largest divisible subset
        
        // Step 2: Build the dp array and prev array.
        // We will use dynamic programming to calculate the largest divisible subset ending at each index.
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                // If nums[i] is divisible by nums[j], we can extend the divisible subset ending at j
                if (nums[i] % nums[j] == 0) {
                    // If extending the subset results in a larger subset, update dp[i] and prev[i]
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;  // Record the index of the previous element
                    }
                }
            }
            // Update maxIndex to the index with the largest subset so far
            if (dp[i] > dp[maxIndex]) {
                maxIndex = i;
            }
        }
        
        // Step 3: Backtrack from maxIndex to find the elements in the largest divisible subset
        vector<int> result;
        int current = maxIndex;
        while (current != -1) {
            result.push_back(nums[current]);
            current = prev[current];  // Move to the previous element in the subset
        }
        
        // Step 4: The result array will contain the largest divisible subset in reverse order.
        // Reverse it to get the correct order.
        reverse(result.begin(), result.end());
        
        return result;  // Return the largest divisible subset
    }
};