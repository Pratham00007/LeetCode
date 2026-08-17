#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
        int n = arr.size();
        int ans=arr[0]+arr[1]+arr[2];
            for(int i=0;i<n-2;i++){
                for(int j=i+1;j<n;j++){
                    
                    for(int k=j+1;k<n;k++){
                        int sum=INT_MIN;
                        sum=arr[i]+arr[j]+arr[k];
                        if(abs(target-ans)>abs(target-sum)){
                            ans=sum;
                        }

                    }
                }
            }
        return ans;
    }
};