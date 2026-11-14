#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int sum=INT_MAX;
        for(int k=l;k<=r;k++){
        for(int i=0;i<=n-k;i++){
           int temp= accumulate(nums.begin()+i,nums.begin()+i+k,0);
           if(temp>0)
           sum=min(sum,temp);
        }
        }
        if(sum!=INT_MAX) return sum;
        return -1;
    }
};