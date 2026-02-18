#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans={-1,-1};        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                ans[0]=i;
                while(i<nums.size() and nums[i]==target )i++;
                ans[1]=i-1;                
            }
        }
        return ans;
    }
};