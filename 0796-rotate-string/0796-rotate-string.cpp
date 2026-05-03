class Solution {
public:
    bool rotateString(string s, string goal) {
        // Check if lengths are equal (necessary condition for rotation)
        // and if goal is a substring of s concatenated with itself
        // This works because any rotation of s will appear as a substring in s+s
        // Example: s = "abcde", goal = "cdeab"
        // s + s = "abcdeabcde" which contains "cdeab"
        return s.size() == goal.size() && strstr((s + s).data(), goal.data());
    }
};