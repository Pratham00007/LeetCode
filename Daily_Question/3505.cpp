#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
     int n, x, k;

    long long min_ops_subarr[100001];

    long long memo[16][100001];

    long long solve(int count, int i) {
        if(count == k)
            return 0;
        
        int sub_arr_need = k-count;
        int ele_need  = sub_arr_need*x;
        int lastIndex       = i + ele_need - 1;

        if(lastIndex >= n) {
            return 1e16; 
        }

        if(memo[count][i] != -1) {
            return memo[count][i];
        }

        long long result = min_ops_subarr[i] + solve(count+1, i+x);


        result = min(result, solve(count, i+1));

        return memo[count][i] = result;

    }

    long long minOperations(vector<int>& nums, int x, int k) {
        this->n = nums.size();
        this->x = x;
        this->k = k;

        memset(memo, -1, sizeof(memo));

        multiset<int> left, right;
        long long l_sum = 0, r_sum = 0;

        int i = 0;
        int j = 0;

        while(j < n) {
            if(left.size() <= right.size()) {
                left.insert(nums[j]);
                l_sum += nums[j];
            } else {
                right.insert(nums[j]);
                r_sum += nums[j];
            }

            if(!left.empty() && !right.empty()) {
                int maxLeft  = *left.rbegin();
                int minRight = *right.begin();

                if(maxLeft > minRight) {
                    left.erase(left.find(maxLeft));
                    right.erase(right.find(minRight));

                    left.insert(minRight);
                    right.insert(maxLeft);

                    l_sum += minRight - maxLeft;
                    r_sum += maxLeft - minRight;
                }
            }

            if(j-i+1 == x) {
                long long median = *left.rbegin();
                long long l_size = left.size();
                long long r_size = right.size();

                min_ops_subarr[i] = (l_size * median - l_sum) + (r_sum - r_size*median);

                if(left.find(nums[i]) != left.end()) {
                    left.erase(left.find(nums[i]));
                    l_sum -= nums[i];
                } else {
                    right.erase(right.find(nums[i]));
                    r_sum -= nums[i];
                }
                i++;
            }

            j++;
        }

        return solve(0, 0); 
    }
};
