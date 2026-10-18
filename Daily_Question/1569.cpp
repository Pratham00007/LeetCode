#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;
    ll MOD = 1e9 + 7;
    
    vector<vector<ll>> PT;
    
    int solve(vector<int>& nums) {
        int m = nums.size();
        
        if(m < 3)
            return 1;
        
        vector<int> lt, rt;
        
        int root = nums[0];
        for(int i = 1; i < m; i++) {
            
            if(nums[i] < root) {
                lt.push_back(nums[i]);
            } else {
                rt.push_back(nums[i]);
            }
            
        }
        
        ll l_ways  = solve(lt)  % MOD;
        ll r_ways = solve(rt) % MOD;
        
        return (((l_ways * r_ways)%MOD) * PT[m-1][lt.size()]) % MOD;
        
    }
    
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        
    
        PT.resize(n+1);
        
        for(int i = 0; i <= n; i++) {
            
            PT[i] = vector<long long>(i+1, 1);
            
            for(int j = 1; j < i; j++) {
                PT[i][j] = (PT[i-1][j-1] + PT[i-1][j]) % MOD;
            }
        }
        
        
        return (solve(nums)-1) % MOD;
    }
};