#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;

        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 1) {
                    bool possible = false;

                    for (int otherCol = 0; otherCol < n; ++otherCol) {
                        if (otherCol != col && grid[row][otherCol] == 1) {
                            possible = true;
                            break;
                        }
                    }

                    if (possible) {
                        ans++;
                    } else {
                        for (int otherRow = 0; otherRow < m; ++otherRow) {
                            if (otherRow != row && grid[otherRow][col] == 1) {
                                possible = true;
                                break;
                            }
                        }

                        if (possible) {
                            ans++;
                        }
                    }
                }
            }
        }

        return ans;
    }
};