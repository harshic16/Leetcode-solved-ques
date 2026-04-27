class Solution {
public:
    vector<int> parent;  // Union-Find parent array
  
    bool hasValidPath(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
      
        // Initialize Union-Find structure
        // Each cell is initially its own parent
        parent.resize(rows * cols);
        for (int i = 0; i < parent.size(); ++i) {
            parent[i] = i;
        }
      
        // Lambda function to connect current cell with left neighbor if compatible
        auto connectLeft = [&](int row, int col) {
            // Check if left neighbor exists and has right-facing connection
            // Street types 1, 4, 6 have right-facing connections
            if (col > 0 && (grid[row][col - 1] == 1 || 
                           grid[row][col - 1] == 4 || 
                           grid[row][col - 1] == 6)) {
                parent[find(row * cols + col)] = find(row * cols + col - 1);
            }
        };
      
        // Lambda function to connect current cell with right neighbor if compatible
        auto connectRight = [&](int row, int col) {
            // Check if right neighbor exists and has left-facing connection
            // Street types 1, 3, 5 have left-facing connections
            if (col < cols - 1 && (grid[row][col + 1] == 1 || 
                                   grid[row][col + 1] == 3 || 
                                   grid[row][col + 1] == 5)) {
                parent[find(row * cols + col)] = find(row * cols + col + 1);
            }
        };
      
        // Lambda function to connect current cell with upper neighbor if compatible
        auto connectUp = [&](int row, int col) {
            // Check if upper neighbor exists and has down-facing connection
            // Street types 2, 3, 4 have down-facing connections
            if (row > 0 && (grid[row - 1][col] == 2 || 
                           grid[row - 1][col] == 3 || 
                           grid[row - 1][col] == 4)) {
                parent[find(row * cols + col)] = find((row - 1) * cols + col);
            }
        };
      
        // Lambda function to connect current cell with lower neighbor if compatible
        auto connectDown = [&](int row, int col) {
            // Check if lower neighbor exists and has up-facing connection
            // Street types 2, 5, 6 have up-facing connections
            if (row < rows - 1 && (grid[row + 1][col] == 2 || 
                                   grid[row + 1][col] == 5 || 
                                   grid[row + 1][col] == 6)) {
                parent[find(row * cols + col)] = find((row + 1) * cols + col);
            }
        };
      
        // Process each cell in the grid
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                int streetType = grid[row][col];
              
                // Connect to neighbors based on street type
                // Type 1: horizontal street (left-right)
                if (streetType == 1) {
                    connectLeft(row, col);
                    connectRight(row, col);
                }
                // Type 2: vertical street (up-down)
                else if (streetType == 2) {
                    connectUp(row, col);
                    connectDown(row, col);
                }
                // Type 3: L-shaped street (left-down)
                else if (streetType == 3) {
                    connectLeft(row, col);
                    connectDown(row, col);
                }
                // Type 4: reversed L-shaped street (right-down)
                else if (streetType == 4) {
                    connectRight(row, col);
                    connectDown(row, col);
                }
                // Type 5: reversed L-shaped street (left-up)
                else if (streetType == 5) {
                    connectLeft(row, col);
                    connectUp(row, col);
                }
                // Type 6: L-shaped street (right-up)
                else {
                    connectRight(row, col);
                    connectUp(row, col);
                }
            }
        }
      
        // Check if start cell (0,0) and end cell (m-1,n-1) are connected
        return find(0) == find(rows * cols - 1);
    }
  
    // Find operation with path compression for Union-Find
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }
};
