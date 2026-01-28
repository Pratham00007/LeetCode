
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]+1!=nums[i+1]){
                return nums[i]+1;
            }
        }
        if(nums[0]!=0){
            return 0;
        }
        return nums[n-1]+1;

    }
};

int main(){
    Solution s;
    vector<int> nums={1,2,3,4};
    // cout<<s.rotate(nums);
    return 0;
}