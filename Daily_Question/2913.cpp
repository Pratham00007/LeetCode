#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int sumCounts(vector<int>& arr) {
        vector<unordered_set<int>>all_subarr;
        int n=arr.size();
        for(int i=0;i<n;i++){
            
            unordered_set<int>temp;
            for(int j=i;j<n;j++){
                temp.insert(arr[j]);
                all_subarr.push_back(temp);
            }
        }
         int ans=0;
        for(int i=0;i<all_subarr.size();i++){
           
            ans+= (all_subarr[i].size()*all_subarr[i].size());
        }
        return ans;
    }
};