class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // Sort the costs array in ascending order to buy cheapest ice creams first
        sort(costs.begin(), costs.end());
      
        // Get the total number of ice cream bars available
        int numIceCreams = costs.size();
      
        // Iterate through sorted costs and buy ice creams while we have enough coins
        for (int i = 0; i < numIceCreams; ++i) {
            // If current ice cream costs more than remaining coins, return count
            if (coins < costs[i]) {
                return i;
            }
          
            // Buy the ice cream by deducting its cost from available coins
            coins -= costs[i];
        }
      
        // If we could afford all ice creams, return the total count
        return numIceCreams;
    }
};
