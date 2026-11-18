#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minChanges(string s) {
        char curr = s[0];

        int count = 0;
        int chg = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {

            if (s[i] == curr) {
                count++;
                continue;
            }

            if (count % 2 == 0) { 
                count = 1;
            } else { 
                count = 0;
                chg++;
            }
            
            curr = s[i];
        }

        return chg;
    }
};