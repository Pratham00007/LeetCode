#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int MOD = 1e9 + 7;

    int maxSum(vector<int> &nums, int k)
    {
        vector<int> count(32, 0);
        //  making a lsit where we store how many ones
        // in this postion of all number
        for (int &num : nums)
        {
            for (int b = 0; b < 32; b++)
            {
                if (num & (1 << b))
                {
                    count[b]++;
                }
            }
        }

        // now transerfing ones to number and redcuing
        //  them and making ther bigger
        long long result = 0;
        while (k--)
        {
            long long curr = 0;
            for (int b = 0; b < 32; b++)
            {
                if (count[b] > 0)
                {
                    count[b]--;
                    curr = (curr | (1 << b));
                }
            }
            result = (result + (curr * curr)) % MOD;
        }

        return result;
    }
};