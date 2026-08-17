#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        if(n==0){
            intervals.push_back(newInterval);
        }
        for(int i=0;i<n-1;i++){
            if(intervals[i][1]>newInterval[0] && intervals[i][0]<newInterval[0]){
                intervals[i][1]=max(intervals[i][1],newInterval[1]);
                
                    while (i<=n-1 && intervals[i][1]>=intervals[i+1][0]){
                        intervals[i][1]=max(intervals[i][1],intervals[i+1][1]);
                        intervals.erase(intervals.begin()+i+1);
                        n--;
                    }
                
            }
            if(intervals[i][1]<newInterval[0] && intervals[i+1][0]>newInterval[1]){
                intervals.push_back(newInterval);
            }

            
        }
        return intervals;
    }
};