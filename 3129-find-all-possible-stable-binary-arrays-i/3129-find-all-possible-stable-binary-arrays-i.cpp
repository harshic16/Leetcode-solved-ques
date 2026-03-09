class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;
        using ll = long long;
      
        // dp[i][j][k] represents the number of stable arrays with i zeros, j ones
        // where k indicates the last element type (0 for zero, 1 for one)
        // Initialize with -1 for memoization
        vector<vector<array<ll, 2>>> dp(zero + 1, vector<array<ll, 2>>(one + 1, {-1, -1}));
      
        // Recursive function with memoization to count stable arrays
        auto countStableArrays = [&](this auto&& countStableArrays, int zerosLeft, int onesLeft, int lastType) -> ll {
            // Base case: invalid state with negative counts
            if (zerosLeft < 0 || onesLeft < 0) {
                return 0;
            }
          
            // Base case: only ones remaining
            if (zerosLeft == 0) {
                // Valid if last element is 1 and consecutive ones don't exceed limit
                return lastType == 1 && onesLeft <= limit;
            }
          
            // Base case: only zeros remaining
            if (onesLeft == 0) {
                // Valid if last element is 0 and consecutive zeros don't exceed limit
                return lastType == 0 && zerosLeft <= limit;
            }
          
            // Check memoization
            ll& result = dp[zerosLeft][onesLeft][lastType];
            if (result != -1) {
                return result;
            }
          
            // Calculate result based on the last element type
            if (lastType == 0) {
                // Last element is 0, so we add a 0 to previous arrays
                // Sum arrays ending with 0 and arrays ending with 1
                // Subtract invalid cases where adding this 0 exceeds the limit
                result = (countStableArrays(zerosLeft - 1, onesLeft, 0) + 
                         countStableArrays(zerosLeft - 1, onesLeft, 1) - 
                         countStableArrays(zerosLeft - limit - 1, onesLeft, 1) + MOD) % MOD;
            } else {
                // Last element is 1, so we add a 1 to previous arrays
                // Sum arrays ending with 0 and arrays ending with 1
                // Subtract invalid cases where adding this 1 exceeds the limit
                result = (countStableArrays(zerosLeft, onesLeft - 1, 0) + 
                         countStableArrays(zerosLeft, onesLeft - 1, 1) - 
                         countStableArrays(zerosLeft, onesLeft - limit - 1, 0) + MOD) % MOD;
            }
          
            return result;
        };
      
        // Calculate total by considering arrays ending with 0 and arrays ending with 1
        return (countStableArrays(zero, one, 0) + countStableArrays(zero, one, 1)) % MOD;
    }
};
