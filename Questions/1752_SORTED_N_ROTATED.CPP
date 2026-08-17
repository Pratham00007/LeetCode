/*
1752. Check if numsay Is Sorted and Rotated
Easy
Topics
premium lock icon
Companies
Hint
Given an numsay nums, return true if the numsay was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original numsay.

Note: An numsay A rotated by x positions results in an numsay B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted numsay.
You can rotate the numsay by x = 2 positions to begin on the element of value 3: [3,4,5,1,2].
Example 2:

Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted numsay once rotated that can make nums.
Example 3:

Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted numsay.
You can rotate the numsay by x = 0 positions (i.e. no rotation) to make nums.
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int>nums2=nums;
    int n=nums.size();
    int temp;
    sort(nums.begin(),nums.end());
    for(int k=0;k<n;k++){
    temp=nums[n-1];
    for(int i=1;i<n;i++){
        nums[n-i]=nums[n-i-1];
    }
    nums[0]=temp;
    for(int j=0;j<n;j++){
        cout<<nums[j];
    }
    cout<<endl;
    if(nums2==nums){
        return true;
    }
    
}
    

    return 0;

    }
};