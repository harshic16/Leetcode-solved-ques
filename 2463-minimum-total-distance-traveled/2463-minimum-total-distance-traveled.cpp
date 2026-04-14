using ll = long long;

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // Sort robots and factories by position for optimal assignment
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
      
        // dp[i][j] = minimum distance to repair robots from index i onwards using factories from index j onwards
        vector<vector<ll>> dp(robot.size(), vector<ll>(factory.size()));
      
        // DFS with memoization to find minimum total distance
        function<ll(int, int)> dfs = [&](int robotIdx, int factoryIdx) -> ll {
            // Base case: all robots have been assigned
            if (robotIdx == robot.size()) {
                return 0;
            }
          
            // Base case: no more factories available but robots remain
            if (factoryIdx == factory.size()) {
                return 1e15;  // Return large value as impossible case
            }
          
            // Return memoized result if already computed
            if (dp[robotIdx][factoryIdx]) {
                return dp[robotIdx][factoryIdx];
            }
          
            // Option 1: Skip current factory and use remaining factories
            ll minDistance = dfs(robotIdx, factoryIdx + 1);
          
            // Option 2: Use current factory for some robots
            ll accumulatedDistance = 0;
            int factoryCapacity = factory[factoryIdx][1];
            int factoryPosition = factory[factoryIdx][0];
          
            // Try assigning k robots to current factory (k from 1 to capacity)
            for (int k = 0; k < factoryCapacity; ++k) {
                // Check if we have enough robots remaining
                if (robotIdx + k >= robot.size()) {
                    break;
                }
              
                // Add distance for current robot to current factory
                accumulatedDistance += abs(robot[robotIdx + k] - factoryPosition);
              
                // Calculate total distance if we assign (k+1) robots to current factory
                // and process remaining robots with remaining factories
                minDistance = min(minDistance, accumulatedDistance + dfs(robotIdx + k + 1, factoryIdx + 1));
            }
          
            // Memoize and return the minimum distance
            dp[robotIdx][factoryIdx] = minDistance;
            return minDistance;
        };
      
        // Start DFS from first robot and first factory
        return dfs(0, 0);
    }
};
