class Solution {
public:
    int numberOfSubstrings(string s) {
        // Array to store the last seen position of each character 'a', 'b', 'c'
        // Initialize with -1 to indicate characters haven't been seen yet
        int lastPosition[3] = {-1, -1, -1};
        int result = 0;
      
        // Iterate through each character in the string
        for (int i = 0; i < s.size(); ++i) {
            // Update the last seen position for the current character
            // s[i] - 'a' converts 'a' to 0, 'b' to 1, 'c' to 2
            lastPosition[s[i] - 'a'] = i;
          
            // Find the minimum position among all three characters
            // This represents the leftmost position where we have all three characters
            int minPosition = min(lastPosition[0], min(lastPosition[1], lastPosition[2]));
          
            // Add the number of valid substrings ending at position i
            // minPosition + 1 gives the count of starting positions that form valid substrings
            result += minPosition + 1;
        }
      
        return result;
    }
};
