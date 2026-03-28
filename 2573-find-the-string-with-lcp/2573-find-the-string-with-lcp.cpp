class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string result(n, '\0');  // Initialize string with null characters
        int currentIndex = 0;
      
        // Step 1: Construct the string based on LCP constraints
        // Try to assign characters 'a' to 'z' to positions in the string
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            // Find the next unassigned position
            while (currentIndex < n && result[currentIndex] != '\0') {
                ++currentIndex;
            }
          
            // If all positions are assigned, we're done
            if (currentIndex == n) {
                break;
            }
          
            // Assign current character to all positions that must have it
            // based on LCP values with currentIndex
            for (int j = currentIndex; j < n; ++j) {
                if (lcp[currentIndex][j] > 0) {
                    result[j] = ch;
                }
            }
        }
      
        // Step 2: Check if all positions have been assigned
        if (result.find('\0') != string::npos) {
            return "";  // Not enough characters to satisfy constraints
        }
      
        // Step 3: Validate the constructed string against LCP matrix
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (result[i] == result[j]) {
                    // Characters match, so LCP should be positive
                    if (i == n - 1 || j == n - 1) {
                        // At boundary: LCP should be exactly 1
                        if (lcp[i][j] != 1) {
                            return "";
                        }
                    } else {
                        // Not at boundary: LCP should follow recurrence relation
                        // lcp[i][j] = lcp[i+1][j+1] + 1
                        if (lcp[i][j] != lcp[i + 1][j + 1] + 1) {
                            return "";
                        }
                    }
                } else {
                    // Characters don't match, so LCP should be 0
                    if (lcp[i][j] != 0) {
                        return "";
                    }
                }
            }
        }
      
        return result;
    }
};
