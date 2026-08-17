
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int xo=0;
        for(int i=0;i<n;i++){
            xo=xo^nums[i];
        }
        return xo;
    }
};