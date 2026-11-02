#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        nth_element(begin(nums),begin(nums)+n/2,end(nums));
        int moves=0;
        int midi=nums[n/2];
        for(int i=0;i<n/2;i++){
            moves+= abs(nums[i]-midi);
            moves+= abs(nums[n-i-1]-midi);
        }

        return moves;
    }
};