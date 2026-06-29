class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
      
        // Iterate through each pattern in the patterns array
        for (const auto& pattern : patterns) {
            // Check if the current pattern is a substring of word
            // find() returns string::npos if pattern is not found
            if (word.find(pattern) != string::npos) {
                count++;
            }
        }
      
        return count;
    }
};
