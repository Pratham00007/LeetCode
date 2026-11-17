#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getCost(int i, int j, string& s) {
        int len = j - i + 1;
        int minChg = 1e9;

        for (int d = 1; d <= len / 2; d++) {
            if (len % d != 0) continue;

            int Chg = 0;
            for (int start = 0; start < d; start++) {
                int left = i + start;
                int right = j - (d - 1 - start);

                while (left < right) {
                    if (s[left] != s[right]) {
                        Chg++;
                    }
                    left += d;
                    right -= d;
                }
            }
            minChg = min(minChg, Chg);
        }
        return minChg;
    }

    int minimumChanges(string s, int k) {
        int n = s.length();

        vector<vector<int>> cost(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                cost[i][j] = getCost(i, j, s);
            }
        }

        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        auto solve = [&](auto& self, int idx, int remK) -> int {
           if (remK == 1) {
                return (idx < n - 1) ? cost[idx][n - 1] : 1e9;
            }
            if (idx >= n) {
                return 1e9;
            }
            if (dp[idx][remK] != -1) {
                return dp[idx][remK];
            }

            int ans = 1e9;
            for (int j = idx + 1; j < n; j++) {
                int currCost = cost[idx][j];
                int nextCost = self(self, j + 1, remK - 1);
                if (nextCost != 1e9) {
                    ans = min(ans, currCost + nextCost);
                }
            }

            return dp[idx][remK] = ans;
        };

        return solve(solve, 0, k);
    }
};