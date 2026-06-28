class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        // Sort the array in ascending order to optimize the arrangement
        sort(arr.begin(), arr.end());
      
        // First element must be 1 according to the problem constraints
        arr[0] = 1;
      
        // Initialize the maximum element tracker
        int maxElement = 1;
      
        // Process each element starting from index 1
        for (int i = 1; i < arr.size(); ++i) {
            // Calculate how much we need to decrease the current element
            // to maintain the constraint: abs(arr[i] - arr[i-1]) <= 1
            // The difference should not exceed 1, so arr[i] can be at most arr[i-1] + 1
            int decrementAmount = max(0, arr[i] - arr[i - 1] - 1);
          
            // Apply the decrement to ensure the constraint is satisfied
            arr[i] -= decrementAmount;
          
            // Update the maximum element found so far
            maxElement = max(maxElement, arr[i]);
        }
      
        // Return the maximum element in the rearranged array
        return maxElement;
    }
};
