class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
      
        string targetPattern = "01";
        int mismatchCount = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] != targetPattern[i & 1]) {
                ++mismatchCount;
            }
        }

        int minFlipsNeeded = min(mismatchCount, n - mismatchCount);
      
        
        for (int i = 0; i < n; ++i) {
            if (s[i] != targetPattern[i & 1]) {
                --mismatchCount;
            }
            if (s[i] != targetPattern[(i + n) & 1]) {
                ++mismatchCount;
            }
            minFlipsNeeded = min({minFlipsNeeded, mismatchCount, n - mismatchCount});
        }
      
        return minFlipsNeeded;
    }
};