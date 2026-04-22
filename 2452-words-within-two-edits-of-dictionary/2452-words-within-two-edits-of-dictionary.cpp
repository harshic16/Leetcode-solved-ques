class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
      
        // Iterate through each query word
        for (auto& queryWord : queries) {
            // Check if current query word matches any dictionary word with at most 2 differences
            for (auto& dictWord : dictionary) {
                int differenceCount = 0;
              
                // Count character differences between query word and dictionary word
                for (int i = 0; i < queryWord.size(); ++i) {
                    if (queryWord[i] != dictWord[i]) {
                        differenceCount++;
                    }
                }
              
                // If at most 2 characters differ, add query word to result and move to next query
                if (differenceCount <= 2) {
                    result.emplace_back(queryWord);
                    break;  // Found a match, no need to check other dictionary words
                }
            }
        }
      
        return result;
    }
};
