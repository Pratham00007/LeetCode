#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> adj;
    vector<int> result;
    vector<int> last;

    void dfs(int currNode, string& s, vector<int>& parent) {
        int c = s[currNode] - 'a';

        int nearest = last[c];

        last[c] = currNode;
        for(int child : adj[currNode]) {
            dfs(child, s, parent);
        }

        last[c] = nearest;

        if(currNode != 0) {
            int newParent = parent[currNode]; 
            if(nearest != -1) {
                newParent = nearest;
            }

            parent[currNode] = newParent;

            result[newParent] += result[currNode];
        }
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        for(int i = 1; i < n; i++) {
            int u = parent[i]; 
            int v = i;
            adj[u].push_back(v); 
        }

        result.assign(n, 1);
        last.assign(26, -1);

        dfs(0, s, parent);

        return result;
    }
};