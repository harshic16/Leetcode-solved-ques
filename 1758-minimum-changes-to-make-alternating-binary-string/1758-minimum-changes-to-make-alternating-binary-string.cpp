class Solution {
public:
    int minOperations(string s) {
        // Count operations needed to match pattern "010101..."
        int operationsForPattern1 = 0;
        int n = s.size();
      
        // Check each position against the alternating pattern starting with '0'
        // At even indices (0, 2, 4...), we expect '0'
        // At odd indices (1, 3, 5...), we expect '1'
        for (int i = 0; i < n; ++i) {
            // i & 1 gives 0 for even indices, 1 for odd indices
            // "01"[i & 1] gives '0' for even positions, '1' for odd positions
            if (s[i] != "01"[i & 1]) {
                operationsForPattern1++;
            }
        }
      
        // The other pattern "101010..." would need (n - operationsForPattern1) operations
        // Return the minimum of the two possibilities
        return min(operationsForPattern1, n - operationsForPattern1);
    }
};