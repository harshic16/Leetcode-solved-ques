class Solution {
public:
    bool checkStrings(string s1, string s2) {
        // Create a 2x26 array to track character counts
        // Row 0: characters at even indices, Row 1: characters at odd indices
        // Each column represents a letter from 'a' to 'z'
        vector<vector<int>> charCount(2, vector<int>(26, 0));
      
        // Iterate through both strings simultaneously
        for (int i = 0; i < s1.size(); ++i) {
            // Determine if current position is even (0) or odd (1)
            int parityIndex = i & 1;  // Bitwise AND with 1 gives 0 for even, 1 for odd
          
            // Increment count for character from s1 at current parity position
            ++charCount[parityIndex][s1[i] - 'a'];
          
            // Decrement count for character from s2 at current parity position
            --charCount[parityIndex][s2[i] - 'a'];
        }
      
        // Check if all character counts are zero
        // If they are, it means s1 and s2 have the same characters at even/odd positions
        for (int i = 0; i < 26; ++i) {
            // Check both even and odd position counts for each character
            if (charCount[0][i] != 0 || charCount[1][i] != 0) {
                return false;
            }
        }
      
        // All counts are zero, strings can be made equal
        return true;
    }
};
