#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minMoves(vector<int>& nums) {
        auto maxi=max_element(nums.begin(),nums.end());
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            cnt+=(*maxi-nums[i]);
        }
        return cnt;
    }
};