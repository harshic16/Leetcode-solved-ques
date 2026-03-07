class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
      
        // Target pattern starting with "01" (alternating pattern)
        string targetPattern = "01";
      
        // Count mismatches when comparing string s with pattern "010101..."
        int mismatchCount = 0;
        for (int i = 0; i < n; ++i) {
            // Use bitwise AND to alternate between indices 0 and 1 of targetPattern
            if (s[i] != targetPattern[i & 1]) {
                ++mismatchCount;
            }
        }
      
        // Initialize answer with minimum flips needed for both patterns:
        // Pattern 1: "010101..." requires mismatchCount flips
        // Pattern 2: "101010..." requires (n - mismatchCount) flips
        int minFlipsNeeded = min(mismatchCount, n - mismatchCount);
      
        // Simulate rotating the string by treating it as circular
        // For each rotation, update mismatch count and find minimum
        for (int i = 0; i < n; ++i) {
            // Remove contribution of character at position i from old window
            if (s[i] != targetPattern[i & 1]) {
                --mismatchCount;
            }
          
            // Add contribution of character at position i in new window
            // After rotation, character at index i moves to position (i + n)
            if (s[i] != targetPattern[(i + n) & 1]) {
                ++mismatchCount;
            }
          
            // Update minimum flips considering both alternating patterns
            minFlipsNeeded = min({minFlipsNeeded, mismatchCount, n - mismatchCount});
        }
      
        return minFlipsNeeded;
    }
};