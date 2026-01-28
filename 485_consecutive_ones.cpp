#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int maxi=0;
        for(int i=0;i<n;i++){
           if (nums[i]==1){
            cnt++;
            maxi=max(cnt,maxi);
           }else{            
           
            cnt=0;
           }
        }
        return maxi;
    }
};

int main(){
    Solution s;
    vector<int> nums={1,2,3,4};
    // cout<<s.rotate(nums);
    return 0;
}