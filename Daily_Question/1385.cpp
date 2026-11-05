#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n=arr1.size();
        int n2=arr2.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            bool is_true=true;
            for(int j=0;j<n2;j++){
                if(abs(arr1[i]-arr2[j])<=d){
                    is_true=false;
                    break;
                }

            }
            if(is_true) cnt++;
        }
        return cnt;
    }
};