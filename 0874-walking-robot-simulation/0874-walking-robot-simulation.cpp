class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Direction vectors: North(0,1), East(1,0), South(0,-1), West(-1,0)
        // Using array to store dx and dy in sequence for easy rotation
        int directions[5] = {0, 1, 0, -1, 0};
      
        // Hash function to convert 2D coordinates to unique integer
        // Multiplier 60010 ensures no collision for valid coordinate range
        auto hashCoordinate = [](int x, int y) {
            return x * 60010 + y;
        };
      
        // Store obstacle positions in hash set for O(1) lookup
        unordered_set<int> obstacleSet;
        for (auto& obstacle : obstacles) {
            obstacleSet.insert(hashCoordinate(obstacle[0], obstacle[1]));
        }
      
        // Initialize robot state
        int maxDistanceSquared = 0;  // Maximum Euclidean distance squared from origin
        int directionIndex = 0;       // Current direction index (0=North, 1=East, 2=South, 3=West)
        int currentX = 0, currentY = 0;  // Current robot position
      
        // Process each command
        for (int command : commands) {
            if (command == -2) {
                // Turn left: rotate counter-clockwise by 90 degrees
                directionIndex = (directionIndex + 3) % 4;
            } else if (command == -1) {
                // Turn right: rotate clockwise by 90 degrees
                directionIndex = (directionIndex + 1) % 4;
            } else {
                // Move forward by 'command' steps
                while (command--) {
                    // Calculate next position
                    int nextX = currentX + directions[directionIndex];
                    int nextY = currentY + directions[directionIndex + 1];
                  
                    // Check if next position has an obstacle
                    if (obstacleSet.count(hashCoordinate(nextX, nextY))) {
                        break;  // Stop moving if obstacle encountered
                    }
                  
                    // Update position
                    currentX = nextX;
                    currentY = nextY;
                  
                    // Update maximum distance squared
                    maxDistanceSquared = max(maxDistanceSquared, currentX * currentX + currentY * currentY);
                }
            }
        }
      
        return maxDistanceSquared;
    }
};
