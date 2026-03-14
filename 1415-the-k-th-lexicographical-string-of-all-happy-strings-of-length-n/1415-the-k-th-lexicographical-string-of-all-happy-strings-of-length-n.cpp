class Solution {
public:
    string getHappyString(int n, int k) {
        // Store all valid happy strings
        vector<string> happyStrings;
      
        // Current string being built
        string currentString = "";
      
        // Define recursive DFS function using lambda
        auto generateHappyStrings = [&](this auto&& generateHappyStrings) -> void {
            // Base case: if current string reaches target length, add to result
            if (currentString.size() == n) {
                happyStrings.emplace_back(currentString);
                return;
            }
          
            // Early termination: stop generating if we already have k strings
            if (happyStrings.size() >= k) {
                return;
            }
          
            // Try adding each character from 'a' to 'c'
            for (char ch = 'a'; ch <= 'c'; ++ch) {
                // Add character only if string is empty or last character is different
                if (currentString.empty() || currentString.back() != ch) {
                    // Add character to current string
                    currentString.push_back(ch);
                  
                    // Recursively generate remaining characters
                    generateHappyStrings();
                  
                    // Backtrack: remove the last added character
                    currentString.pop_back();
                }
            }
        };
      
        // Start the DFS generation process
        generateHappyStrings();
      
        // Return k-th happy string if it exists, otherwise return empty string
        return happyStrings.size() < k ? "" : happyStrings[k - 1];
    }
};
