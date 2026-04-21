class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
      
        // Initialize parent array for Union-Find (Disjoint Set Union)
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0); // Initialize each element as its own parent
      
        // Find function with path compression for Union-Find
        function<int(int)> findRoot = [&](int x) {
            if (x == parent[x]) {
                return x;
            }
            // Path compression: make every node point directly to root
            return parent[x] = findRoot(parent[x]);
        };
      
        // Union operation: merge connected components based on allowed swaps
        for (auto& swap : allowedSwaps) {
            int root1 = findRoot(swap[0]);
            int root2 = findRoot(swap[1]);
            parent[root1] = root2; // Union the two components
        }
      
        // Count frequency of each value in source array for each connected component
        // Key: component root, Value: map of (value -> frequency)
        unordered_map<int, unordered_map<int, int>> componentValueCount;
        for (int i = 0; i < n; ++i) {
            int root = findRoot(i);
            componentValueCount[root][source[i]]++;
        }
      
        // Calculate minimum Hamming distance
        int hammingDistance = 0;
        for (int i = 0; i < n; ++i) {
            int root = findRoot(i);
            // Decrement the count of target[i] in the component
            // If count becomes negative, it means we don't have enough of this value
            // in the component to match the target
            if (--componentValueCount[root][target[i]] < 0) {
                hammingDistance++;
            }
        }
      
        return hammingDistance;
    }
};
