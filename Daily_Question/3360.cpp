#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10)return false;
        n=n-10;
        bool is_bob=false;
        bool is_alice=true;
        
        for(int i=9;i>0;i--){
            if((n-i)>=0){ n=n-i;is_bob=!is_bob;is_alice=!is_alice;}
            else break;
        }
        return is_alice;
       
    }
};