class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        using ll = long long;

        // Binary search bounds: minimum 1 second, maximum 10^16 seconds
        ll left = 1;
        ll right = 1e16;

        // Lambda function to check if given time is sufficient to reduce mountain to 0
        auto canCompleteInTime = [&](ll timeLimit) -> bool {
            ll totalHeightReduced = 0;

            // For each worker, calculate how much height they can reduce in given time
            for (int& workerTime : workerTimes) {
                // Worker reduces height by 1, 2, 3, ... units
                // Time taken: workerTime * (1 + 2 + 3 + ... + n) = workerTime * n * (n + 1) / 2
                // Given timeLimit, solve for n: workerTime * n * (n + 1) / 2 <= timeLimit
                // This gives us a quadratic equation: n^2 + n - 2*timeLimit/workerTime <= 0
                // Using quadratic formula: n = (-1 + sqrt(1 + 8*timeLimit/workerTime)) / 2
                // Simplified calculation below
                totalHeightReduced += static_cast<ll>(sqrt(timeLimit * 2.0 / workerTime + 0.25) - 0.5);
            }

            // Check if total height reduced meets or exceeds the mountain height
            return totalHeightReduced >= mountainHeight;
        };

        // Binary search using standard template
        ll firstTrueIndex = -1;

        while (left <= right) {
            ll mid = left + (right - left) / 2;

            if (canCompleteInTime(mid)) {
                // Feasible: can complete in 'mid' seconds
                firstTrueIndex = mid;
                right = mid - 1;  // Try to find smaller time
            } else {
                // Not feasible: need more time
                left = mid + 1;
            }
        }

        return firstTrueIndex;
    }
};
