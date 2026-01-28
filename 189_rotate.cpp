/*
189. Rotate Array
Medium
Topics
premium lock icon
Companies
Hint
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        // time limit exceeds
        // int n=nums.size();
        // for (int i=0;i<k;i++){
        //     int temp=nums[n-1];
        //     for(int j=1;j<n;j++){
        //         nums[n-j]=nums[n-j-1];
        //     }
        //     nums[0]=temp;
        // }

        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};

int main(){
    Solution s;
    vector<int> nums={1,2,3,4};
    s.rotate(nums,3);
    for(auto it:nums){
        cout<<it;
    }
    return 0;
}