#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long>sq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sq.push_back(nums[i]*nums[i]);
        }
        sort(sq.begin(),sq.end());
        int i=0,j=n-1;
        long long ans=0;
        while(i<j){
            ans=ans+(sq[j]-sq[i]);
            i++;j--;

        }
        if(i==j) ans=ans+sq[i];
        return ans;
    }
};