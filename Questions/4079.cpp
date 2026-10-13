#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

bool check_prime(int num){
    for(int i=2;i<=pow(num,0.5);i++){
        if(num%i==0)return false;
    }
    return true;
}
    vector<int> maxPrimes(int n, int s) {
        int last=0;
        vector<int>ans;
        for(int i=n;i>1;i--){
            if (check_prime(i)) {last=i; break; }
        }
        if (last==0) return ans;
        ans.push_back(2);
        int sum=2;
        for(int i=2;i<last;i++){
            if(check_prime(i)){
                sum+=i;
                ans.push_back(i);
            }
            if(sum>s){
                sum-=i;
                ans.pop_back();                
            }
        }
        return ans;
    }
};

// TLE use theorem of etherisis for prime no.