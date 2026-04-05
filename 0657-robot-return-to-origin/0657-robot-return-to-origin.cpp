class Solution {
public:
    /**
     * Determines if a robot returns to the origin after executing all moves.
     * The robot starts at position (0, 0) on a 2D plane.
     * 
     * @param moves A string containing move commands:
     *              'U' - move up (increase y-coordinate)
     *              'D' - move down (decrease y-coordinate)
     *              'L' - move left (decrease x-coordinate)
     *              'R' - move right (increase x-coordinate)
     * @return true if the robot returns to origin (0, 0), false otherwise
     */
    bool judgeCircle(string moves) {
        // Initialize coordinates to track robot's position
        int xCoordinate = 0;
        int yCoordinate = 0;
      
        // Process each move command
        for (char move : moves) {
            switch (move) {
                case 'U':  // Move up
                    yCoordinate++;
                    break;
                case 'D':  // Move down
                    yCoordinate--;
                    break;
                case 'L':  // Move left
                    xCoordinate--;
                    break;
                case 'R':  // Move right
                    xCoordinate++;
                    break;
            }
        }
      
        // Check if robot returned to origin
        return (xCoordinate == 0 && yCoordinate == 0);
    }
};
