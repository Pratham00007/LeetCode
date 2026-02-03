
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int i=0;
        int j=0;
        while (i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        if(i<nums1.size()){
            while(i<nums1.size()){
            ans.push_back(nums1[i]);
            i++;
            }
        }
        if(j<nums2.size()){
            while(j<nums2.size()){
                ans.push_back(nums2[j]);
                j++;
            }
        }

        for(auto it:ans){
            cout<<it;
        }
        // median
        int si=ans.size();
        double median=0;
        if (si%2==0){
            median=(ans[(si/2)-1]+ans[(si/2)])/2.0;
        }else{
            median=ans[((si+1)/2.0)-1];
        }

        return median;
    }
};


int main(){
    Solution s;
    vector<int> nums1={1,3};
    vector<int> nums2={2,4};
    cout<<s.findMedianSortedArrays(nums1,nums2);
    return 0;
}