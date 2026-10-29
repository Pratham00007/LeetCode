#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> adj;
    int n;
    vector<int> tin, tout, eulerTour;
    int time;

    vector<int> ST;

    vector<vector<int>> AT;
    vector<int> depth;
    int cols;

    void dfs(int node, int parent, int d, string& s) {
        depth[node] = d;
        AT[node][0] = parent;

        tin[node] = time;
        eulerTour[time] = (1 << (s[node] - 'a')); 
        time++;

        for(int &child : adj[node]) {
            if(child == parent) {
                continue;
            }
            dfs(child, node, d+1, s);
        }

        tout[node] = time;
        eulerTour[time] = (1 << (s[node] - 'a')); 
        time++;
    }

    void bldST(int i, int l, int r, vector<int>& nums) {
        if(l == r) {
            ST[i] = nums[l];
            return;
        }

        int mid = l + (r-l)/2;
        bldST(2*i+1, l, mid, nums);
        bldST(2*i+2, mid+1, r, nums);
        ST[i] = ST[2*i+1] ^ ST[2*i+2];
    }

    void uptST(int index, int val, int i, int l, int r) {
        if(l == r) {
            ST[i] = val;
            return;
        }

        int mid = l + (r-l)/2;
        if(index <= mid) {
            uptST(index, val, 2*i+1, l, mid);
        } else {
            uptST(index, val, 2*i+2, mid+1, r);
        }

        ST[i] = ST[2*i+1] ^ ST[2*i+2];
    }

    int qryST(int start, int end, int i, int l, int r) {
        if(l > end || r < start) {
            return 0;
        }

        if(l >= start && r <= end) {
            return ST[i];
        }

        int mid = l + (r-l)/2;
        return qryST(start, end, 2*i+1, l,    mid) ^
               qryST(start, end, 2*i+2, mid+1, r);
    }

    void bldAT() {
        for(int j = 1; j < cols; j++) {
            for(int node = 0; node < n; node++) {
                if(AT[node][j-1] != -1) {
                    AT[node][j] = AT[ AT[node][j-1] ][j-1];
                }
            }
        }
    }

    int getLCA(int u, int v) {
        if(depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];
        for(int j = 0; j < cols; j++) {
            if(diff & (1 << j)) {
                u = AT[u][j];
            }
        }

        if(u == v) 
            return u;

        for(int j = cols - 1; j >= 0; j--) {
            if(AT[u][j] != AT[v][j]) {
                u = AT[u][j];
                v = AT[v][j];
            }
        }

        return AT[u][0];
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        eulerTour.assign(2*n, 0); 

        time = 0;
        cols = log2(n) + 1;
        AT.assign(n, vector<int>(cols, -1));
        
        dfs(0, -1, 0, s);


        int N = 2*n; 
        ST.resize(4*N, 0);
        bldST(0, 0, N-1, eulerTour);
        
        bldAT();

        vector<bool> result;

        for(string &q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;

            if(type == "update") { 
                int node;
                char c;

                ss >> node >> c;

                int charValue = (1 << (c - 'a'));
                s[node] = c;
                uptST(tin[node], charValue, 0, 0, 2*n-1);
                uptST(tout[node], charValue, 0, 0, 2*n-1);
            } else { 
                int u, v;

                ss >> u >> v;

                int lcaNode = getLCA(u, v);
                char ch = s[lcaNode];
                int charValue = (1 << (ch - 'a'));

                int mask = qryST(0, tin[u], 0, 0, 2*n-1) ^
                           qryST(0, tin[v], 0, 0, 2*n-1) ^
                           charValue;
                
                result.push_back((mask & (mask-1)) == 0);       
            }
        }
        return result;

    }
};