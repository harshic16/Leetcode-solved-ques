class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxDist = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();

        for (int i = 0; i < n1; ++i) {
            int value = nums1[i];

            // Binary search to find the first index j where nums2[j] < value
            // Using the standard template: find first true index
            int left = i;
            int right = n2 - 1;
            int firstTrueIndex = -1;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums2[mid] < value) {  // feasible condition: pair becomes invalid
                    firstTrueIndex = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            // Calculate the last valid j
            int lastValidJ;
            if (firstTrueIndex == -1) {
                // All positions from i to end are valid
                lastValidJ = n2 - 1;
            } else {
                // Last valid position is one before first invalid
                lastValidJ = firstTrueIndex - 1;
            }

            // Update maximum distance if valid pair exists
            if (lastValidJ >= i) {
                maxDist = max(maxDist, lastValidJ - i);
            }
        }

        return maxDist;
    }
};
