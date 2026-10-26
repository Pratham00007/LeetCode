#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int m, n;
    vector<vector<int>>direc={{0,1},{0,-1},{1,0},{-1,0}};

    long long dfs(int i,int j,vector<vector<int>>&grid){
        long long sum=grid[i][j];
        grid[i][j]=0;

        for(vector<int>&dir:direc){
            int i2=i+dir[0];
            int j2=j+dir[1];

            if(i2>=0 && i2<m && j2>=0 && j2<n && grid[i2][j2]>0){
                sum+=dfs(i2,j2,grid);
            }
        }
        return sum;
    }
    
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        
        int cnt = 0;
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                
                if(grid[i][j] > 0) {
                    long long sum=dfs(i,j,grid);
                    if(sum%k==0) cnt++;
                }                
            }
        }
        
        return cnt;
    }
};