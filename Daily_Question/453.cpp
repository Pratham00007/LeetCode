#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
       
        int mini=INT_MAX;
        int sume=0;
        for(int i=0;i<n;i++){
            mini=min(mini,nums[i]);
            sume+=nums[i];
        }

        return sume-(n*mini);
    }
};