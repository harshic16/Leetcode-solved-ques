class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int arraySize = nums.size();
        int doubledSize = arraySize * 2;  // Double the array to handle circular nature

        // Initialize minimum distances array with maximum possible value
        vector<int> minDistances(doubledSize, doubledSize);

        // First pass: Find minimum distance to previous occurrence (left to right)
        unordered_map<int, int> lastSeenIndex;
        for (int i = 0; i < doubledSize; i++) {
            int currentValue = nums[i % arraySize];

            // If we've seen this value before, calculate distance
            if (lastSeenIndex.count(currentValue)) {
                minDistances[i] = min(minDistances[i], i - lastSeenIndex[currentValue]);
            }

            // Update last seen index for this value
            lastSeenIndex[currentValue] = i;
        }

        // Second pass: Find minimum distance to next occurrence (right to left)
        unordered_map<int, int> nextSeenIndex;
        for (int i = doubledSize - 1; i >= 0; i--) {
            int currentValue = nums[i % arraySize];

            // If we've seen this value in future positions, calculate distance
            if (nextSeenIndex.count(currentValue)) {
                minDistances[i] = min(minDistances[i], nextSeenIndex[currentValue] - i);
            }

            // Update next seen index for this value
            nextSeenIndex[currentValue] = i;
        }

        // Merge results from doubled array back to original array size
        // Take minimum between position i and position i+n (circular wrap)
        for (int i = 0; i < arraySize; i++) {
            minDistances[i] = min(minDistances[i], minDistances[i + arraySize]);
        }

        // Process queries and build result
        vector<int> result;
        for (int queryIndex : queries) {
            // If minimum distance is >= array size, no duplicate exists
            result.push_back(minDistances[queryIndex] >= arraySize ? -1 : minDistances[queryIndex]);
        }

        return result;
    }
};
