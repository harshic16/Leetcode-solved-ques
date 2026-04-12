class Solution {
public:
    int minimumDistance(string word) {
        int wordLength = word.size();
        const int INF = 1 << 30;  // Large value representing infinity
      
        // dp[i][leftFinger][rightFinger] = minimum distance to type first i+1 characters
        // with left finger on position leftFinger and right finger on position rightFinger
        vector<vector<vector<int>>> dp(wordLength, 
                                       vector<vector<int>>(26, 
                                                          vector<int>(26, INF)));
      
        // Initialize first character - can be typed with either finger at no cost
        // The other finger can be at any position
        for (int otherFinger = 0; otherFinger < 26; ++otherFinger) {
            dp[0][word[0] - 'A'][otherFinger] = 0;  // First char typed with left finger
            dp[0][otherFinger][word[0] - 'A'] = 0;  // First char typed with right finger
        }
      
        // Process each subsequent character
        for (int i = 1; i < wordLength; ++i) {
            int prevChar = word[i - 1] - 'A';  // Previous character position
            int currChar = word[i] - 'A';      // Current character to type
            int moveDist = dist(prevChar, currChar);  // Distance between consecutive chars
          
            // Try all possible finger configurations
            for (int otherFinger = 0; otherFinger < 26; ++otherFinger) {
                // Case 1: Same finger that typed previous char types current char
                // Left finger moves from prevChar to currChar, right stays at otherFinger
                dp[i][currChar][otherFinger] = min(dp[i][currChar][otherFinger], 
                                                   dp[i - 1][prevChar][otherFinger] + moveDist);
              
                // Right finger moves from prevChar to currChar, left stays at otherFinger
                dp[i][otherFinger][currChar] = min(dp[i][otherFinger][currChar], 
                                                   dp[i - 1][otherFinger][prevChar] + moveDist);
              
                // Case 2: The other finger (not at prevChar) types current char
                if (otherFinger == prevChar) {
                    // The finger at otherFinger position was the one that typed previous char
                    // So we use the other finger to type current char
                    for (int prevOtherFinger = 0; prevOtherFinger < 26; ++prevOtherFinger) {
                        int otherFingerDist = dist(prevOtherFinger, currChar);
                      
                        // Left finger was at prevOtherFinger, moves to currChar
                        dp[i][currChar][otherFinger] = min(dp[i][currChar][otherFinger], 
                                                           dp[i - 1][prevOtherFinger][prevChar] + otherFingerDist);
                      
                        // Right finger was at prevOtherFinger, moves to currChar
                        dp[i][otherFinger][currChar] = min(dp[i][otherFinger][currChar], 
                                                           dp[i - 1][prevChar][prevOtherFinger] + otherFingerDist);
                    }
                }
            }
        }
      
        // Find minimum distance among all valid final configurations
        // One finger must be at the last character position
        int minDistance = INF;
        int lastChar = word[wordLength - 1] - 'A';
      
        for (int otherFinger = 0; otherFinger < 26; ++otherFinger) {
            minDistance = min(minDistance, dp[wordLength - 1][lastChar][otherFinger]);
            minDistance = min(minDistance, dp[wordLength - 1][otherFinger][lastChar]);
        }
      
        return minDistance;
    }
  
    // Calculate Manhattan distance between two keys on a 6x5 keyboard layout
    // Keys are arranged as: A=0, B=1, ..., Z=25
    // Keyboard layout: 6 columns per row
    int dist(int keyA, int keyB) {
        int rowA = keyA / 6, colA = keyA % 6;
        int rowB = keyB / 6, colB = keyB % 6;
        return abs(rowA - rowB) + abs(colA - colB);
    }
};
