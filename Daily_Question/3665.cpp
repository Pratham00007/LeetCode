#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int LEFT = 0; 
    int UP = 1; 
    int MOD = 1e9+7;
    int m; 
    int n; 
    int solve(vector<vector<int>>& grid, int i, int j, int cameFrom, vector<vector<array<int, 2>>>& t) {
        if(i >= m || j >= n) {
            return 0;
        }

        if(i == m-1 && j == n-1)
            return 1;
        

        if(t[i][j][cameFrom] != -1) {
            return t[i][j][cameFrom];
        }
        
        if(grid[i][j] == 1) { 
            if(cameFrom == LEFT) {
                return t[i][j][cameFrom] = solve(grid, i+1, j, UP, t);
            } else {
                return t[i][j][cameFrom] = solve(grid, i, j+1, LEFT, t);
            }
        }

        int tot_pt_cnt = 0;
        tot_pt_cnt = (tot_pt_cnt + solve(grid, i, j+1, LEFT, t)) % MOD;
        tot_pt_cnt = (tot_pt_cnt + solve(grid, i+1, j, UP, t)) % MOD;

        return t[i][j][cameFrom] = tot_pt_cnt;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<array<int, 2>>> t(m+1, vector<array<int, 2>>(n, {-1, -1}));

        return solve(grid, 0, 0, LEFT, t);
    }
};

