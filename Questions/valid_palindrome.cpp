/*

A phrase is a palindrome if, after converting all uppercase letters into 
lowercase letters and removing all non-alphanumeric characters, it reads 
the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.

*/
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        string after;
        transform(s.begin(),s.end(),s.begin(),[](unsigned char c ){return tolower(c);});
        int n=s.length();
        
        for (int i=0;i<n;i++){
            if (s[i] == ' '){}
            else if(isalpha(s[i])||isalnum(s[i])){
                after+=s[i];
            }
            
            else{};
        }
        
        string rev;
        for(int j=after.length()-1;j>-1;j--){
            rev+=after[j];
        }
        
        if(after==rev){
           return true;
        }else{
            return false;
        }
    }
};
