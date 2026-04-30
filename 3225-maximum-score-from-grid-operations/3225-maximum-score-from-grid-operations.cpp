#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) {
            return 0;
        }

        vector<vector<vector<long long>>> dp(
            n,
            vector<vector<long long>>(n + 1, vector<long long>(n + 1, 0))
        );
        vector<vector<long long>> prevMax(n + 1, vector<long long>(n + 1, 0));
        vector<vector<long long>> prevSuffixMax(n + 1, vector<long long>(n + 1, 0));
        vector<vector<long long>> colSum(n, vector<long long>(n + 1, 0));

        for (int c = 0; c < n; c++) {
            for (int r = 1; r <= n; r++) {
                colSum[c][r] = colSum[c][r - 1] + grid[r - 1][c];
            }
        }

        for (int i = 1; i < n; i++) {
            for (int currH = 0; currH <= n; currH++) {
                for (int prevH = 0; prevH <= n; prevH++) {
                    if (currH <= prevH) {
                        long long extraScore = colSum[i][prevH] - colSum[i][currH];
                        dp[i][currH][prevH] = prevSuffixMax[prevH][0] + extraScore;
                    } else {
                        long long extraScore = colSum[i - 1][currH] - colSum[i - 1][prevH];
                        dp[i][currH][prevH] = max(
                            prevSuffixMax[prevH][currH],
                            prevMax[prevH][currH] + extraScore
                        );
                    }
                }
            }

            for (int currH = 0; currH <= n; currH++) {
                prevMax[currH][0] = dp[i][currH][0];
                for (int prevH = 1; prevH <= n; prevH++) {
                    long long penalty = prevH > currH
                        ? colSum[i][prevH] - colSum[i][currH]
                        : 0;
                    prevMax[currH][prevH] = max(
                        prevMax[currH][prevH - 1],
                        dp[i][currH][prevH] - penalty
                    );
                }

                prevSuffixMax[currH][n] = dp[i][currH][n];
                for (int prevH = n - 1; prevH >= 0; prevH--) {
                    prevSuffixMax[currH][prevH] = max(
                        prevSuffixMax[currH][prevH + 1],
                        dp[i][currH][prevH]
                    );
                }
            }
        }

        long long answer = 0;
        for (int k = 0; k <= n; k++) {
            answer = max(answer, max(dp[n - 1][0][k], dp[n - 1][n][k]));
        }

        return answer;
    }
};