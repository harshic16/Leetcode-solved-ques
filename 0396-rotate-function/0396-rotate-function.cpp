class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        // Calculate initial F(0) and sum of all elements
        int currentFunctionValue = 0;
        int sumOfAllElements = 0;
        int arraySize = nums.size();
      
        // Initialize F(0) = 0*nums[0] + 1*nums[1] + ... + (n-1)*nums[n-1]
        // Also calculate the sum of all array elements
        for (int i = 0; i < arraySize; ++i) {
            currentFunctionValue += i * nums[i];
            sumOfAllElements += nums[i];
        }
      
        // Track the maximum function value found
        int maxFunctionValue = currentFunctionValue;
      
        // Calculate F(k) for k = 1 to n-1 using the recurrence relation:
        // F(k) = F(k-1) + sum - n * nums[n-k]
        // This relation comes from the observation that rotating right by 1 position
        // increases all indices by 1 (mod n), except the last element becomes first
        for (int rotation = 1; rotation < arraySize; ++rotation) {
            // Update function value using the recurrence relation
            currentFunctionValue = currentFunctionValue + sumOfAllElements - arraySize * nums[arraySize - rotation];
          
            // Update maximum if current value is larger
            maxFunctionValue = max(maxFunctionValue, currentFunctionValue);
        }
      
        return maxFunctionValue;
    }
};