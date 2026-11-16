#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digi_sum(string st) {
        int sum = 0;
        for (char c : st) {
            sum += c - '0';
        }
        return sum;
    }

    string digitSum(string s, int k) {
        int n = s.size();

        while (n>k) {
            int i=0;
            string ans = "";

            while (i+k<=n) {
                int digi = digi_sum(s.substr(i, k));
                i+=k;
                ans += to_string(digi);
            }

            if (i<n) {
                ans += to_string(digi_sum(s.substr(i)));
            }

            s = ans;
            n = s.size();
        }

        return s;
    }
};
