class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        // Bitmask to track which counts of '1's have been used
        // If bit i is set, it means there exists a string with i ones
        int usedOnesCounts = 0;
      
        // For each binary string, count the number of '1's and mark that count as used
        for (const auto& binaryStr : nums) {
            int onesCount = count(binaryStr.begin(), binaryStr.end(), '1');
            usedOnesCounts |= (1 << onesCount);
        }
      
        // Find the first unused count of '1's
        for (int i = 0; ; ++i) {
            // Check if bit i is not set (count i is unused)
            if ((usedOnesCounts >> i & 1) ^ 1) {
                // Construct a binary string with i ones followed by (n-i) zeros
                // This guarantees a different string since no existing string has exactly i ones
                return string(i, '1') + string(nums.size() - i, '0');
            }
        }
    }
};