class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;

        // Fix the left endpoint of the subarray at index 'left'
        for (int left = 0; left < n; ++left) {
            // Count occurrences of each value in the current subarray
            unordered_map<int, int> count;

            // Extend the subarray to the right, ending at index 'right'
            for (int right = left; right < n; ++right) {
                // Current subarray length is nums[left..right]
                int length = right - left + 1;

                // Include the new rightmost element in the frequency count
                count[nums[right]]++;

                // 'target' is the majority element if it appears strictly
                // more than half the time in the subarray
                if (count[target] > length / 2) {
                    ++ans;
                }
            }
        }

        return ans;
    }
};
