#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int longestMonotonicSubarray(vector<int>& a) {
        int ans = 1, inc = 1, dec = 1;

        for (int i = 1; i < a.size(); i++) {
            if (a[i] > a[i - 1]) {
                inc++;
                dec = 1;
            } 
            else if (a[i] < a[i - 1]) {
                dec++;
                inc = 1;
            } 
            else {
                inc = dec = 1;
            }

            ans = max({ans, inc, dec});
        }

        return ans;
    }
};
