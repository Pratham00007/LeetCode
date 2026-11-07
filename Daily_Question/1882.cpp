#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
   typedef pair<int, int> P;
    typedef tuple<long, int, int> T; 

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        priority_queue<P, vector<P>, greater<P>> f_server;

        priority_queue<T, vector<T>, greater<T>> b_server;


        for(int i = 0; i < n; i++) { 
            f_server.push({servers[i], i}); 
        }

        vector<int> result(m);

        for(int i = 0; i < m; i++) { 
            while(!b_server.empty() && get<0>(b_server.top()) <= i) {
                auto [finTime, wt, idx] = b_server.top();
                b_server.pop();
                f_server.push({wt, idx});
            }


            if(f_server.empty()) {
                auto [finTime, wt, idx] = b_server.top();
                b_server.pop();
                result[i] = idx;
                b_server.push({finTime + tasks[i], wt, idx});
            } else { 
                auto [wt, idx] = f_server.top();
                f_server.pop();
                result[i] = idx;
                b_server.push({i + tasks[i], wt, idx});
            }
        }

        return result;  
    }
};