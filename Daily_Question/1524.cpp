#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7;

        long long odd = 0, even = 1;
        long long sum = 0, ans = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            if (sum % 2 != 0) {
                ans = (ans + even) % mod;
                odd++;
            }
            else {
                ans = (ans + odd) % mod;
                even++;
            }
        }

        return ans;
    }
};