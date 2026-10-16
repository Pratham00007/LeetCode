#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

int mod=1e9+7;
    int sumCounts(vector<int>& arr) {
        
        int n=arr.size();
        int ans=0;

        for(int i=0;i<n;i++){
            
            unordered_set<int>temp;
            for(int j=i;j<n;j++){
                temp.insert(arr[j]);
                
                long long cnt = temp.size();
                ans = (ans + cnt * cnt) % mod;
            }
        }
         
        return ans;
    }
};

// TLE