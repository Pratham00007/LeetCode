#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkString(string s) {
        bool a_appear=false;
        bool b_appear=false;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='b') b_appear=true;
            else if(s[i]=='a') {
                if(b_appear) return false;
                a_appear=true;
                }           
            
        }
        return true;
    }
};