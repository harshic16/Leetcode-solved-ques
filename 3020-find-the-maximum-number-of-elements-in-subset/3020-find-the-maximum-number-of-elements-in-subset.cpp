class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // Count frequency of each number in the array
        unordered_map<long long, int> frequencyMap;
        for (int number : nums) {
            ++frequencyMap[number];
        }
      
        // Special handling for 1: can form a sequence of all 1s
        // If count is odd, use all; if even, use count-1 to maintain odd length
        int maxLength = frequencyMap[1] - (frequencyMap[1] % 2 ^ 1);
      
        // Remove 1 from consideration for the main algorithm
        frequencyMap.erase(1);
      
        // Check each unique number as a potential base of geometric sequence
        for (auto [baseValue, frequency] : frequencyMap) {
            int currentLength = 0;
            long long currentValue = baseValue;
          
            // Build sequence: base, base^2, base^4, base^8, ...
            // Continue while current value exists with frequency >= 2
            while (frequencyMap.count(currentValue) && frequencyMap[currentValue] > 1) {
                currentValue = currentValue * currentValue;  // Square the value
                currentLength += 2;  // Add 2 for symmetric pattern (e.g., x, x^2, x)
            }
          
            // Add final element if it exists (peak of sequence), otherwise subtract 1
            // This handles the middle element of palindrome-like sequence
            currentLength += frequencyMap.count(currentValue) ? 1 : -1;
          
            // Update maximum length found so far
            maxLength = max(maxLength, currentLength);
        }
      
        return maxLength;
    }
};
