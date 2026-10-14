#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int find_sum(int number){
        int sum=0;
        while(number){
            sum=sum+number%10;
            number=number/10;
        }
        return sum;
    }
    int find_sq(int number){
        int sum=0;
        while(number){
            sum=sum+(number%10)*(number%10);
            number=number/10;
        }
        return sum;
    }


    vector<int>num_vc(int nume){
        vector<int>num_vec;
        while(nume){
            num_vec.push_back(nume%10);
            nume=nume/10;
        }
        return num_vec;
    }

    void max_digit(vector<int>&ans_vec){
        sort(ans_vec.begin(),ans_vec.end());
                
        int last=ans_vec.size()-1;
        int start=0;

        while(start<last){
        if(ans_vec[last]+ans_vec[start]>9) {last--;}
        else{
            ans_vec[last]=ans_vec[last]+ans_vec[start];
            ans_vec[start]=0;
            start++;
        }
        
    }

                

    }

    string vec_str(vector<int>arr){
        string ans="";
        for(int i=0;i<arr.size();i++){
            ans.push_back(arr[i]+'0');
        }
        return ans;
    }

    string maxSumOfSquares(int num, int sum) {
        int start=1;
        int end=9;
        int temp=num;
        int max_sum=0;
        string ans="";
        while(temp>1){
            start=start*10;
            end=(end*10)+9;
            temp--;
        }
        for(int i=start;i<=end;i++){
            if(find_sum(i)==sum){
                vector<int> ans_vec=num_vc(i);

                max_digit(ans_vec);

                sort(ans_vec.begin(),ans_vec.end());

                ans=vec_str(ans_vec);           
                
                 
            }
        }
        
        return ans;

    }
};