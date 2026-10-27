#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>grid(m,string(n,'#'));
        for(int j=0;j<n;j++) grid[0][j]='.';
        for(int k=0;k<m;k++) grid[k][n-1]='.';
        
    return grid;
    }
};