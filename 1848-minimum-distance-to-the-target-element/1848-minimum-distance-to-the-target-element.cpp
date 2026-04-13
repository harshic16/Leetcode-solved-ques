class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        // Get the size of the input array
        int arraySize = nums.size();
      
        // Initialize minimum distance to maximum possible value (array size)
        int minDistance = arraySize;
      
        // Iterate through each element in the array
        for (int i = 0; i < arraySize; ++i) {
            // Check if current element equals the target value
            if (nums[i] == target) {
                // Update minimum distance if current distance is smaller
                minDistance = min(minDistance, abs(i - start));
            }
        }
      
        // Return the minimum distance found
        return minDistance;
    }
};
