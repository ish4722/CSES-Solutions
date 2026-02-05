//in this qus u learn abvout finding the nodes in a path so we use sam difference techniwue initially 
//then we perform a dfs to accumulate the results 

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <random>
#include <cassert>

using namespace std;

void dfs(int node,vector<vector<int>>& adj, vector<int>& depth, vector<int>& parent){

    for(auto child: adj[node]){
        if(child!=parent[node]){
            parent[child]=node;
            depth[child]=depth[node]+1;
            dfs(child,adj,depth,parent);
        }
    }
}

void dfs2(int u, int p, vector<vector<int>>& adj, vector<int>& cnt) {
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs2(v, u, adj, cnt);
        cnt[u] += cnt[v];
    }
}


int lca(int a, int b, vector<int>& depth , vector<vector<int>>& up){
    if(depth[a]<depth[b]){
        swap(a,b);
    }

    int LOG=up[0].size();

    int diff=depth[a]-depth[b];
    for(int j=0;j<LOG;j++){
        if(diff & (1<<j)){
            a=up[a][j];
        }
    }

    if(a==b){
        return a;
    }

    for(int j=LOG-1;j>=0;j--){
        if(up[a][j]!=up[b][j]){
            a=up[a][j];
            b=up[b][j];
        }
    }
    return up[a][0];
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    int n,q;
    cin>>n>>q;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    const int LOG = 20;
    vector<vector<int>> up(n + 1, vector<int>(LOG));
    vector<int> depth(n + 1);
    vector<int> parent(n + 1, -1);

    depth[1] = 0;
    dfs(1, adj, depth, parent);

    for(int i=0;i<=n;i++){
        up[i][0]=parent[i];
    }

    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            if (up[i][j - 1] != -1) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            } else {
                up[i][j] = -1;
            }
        }
    }

    // vector<int> ans(n+1,0);
    // while(q--){
    //     int a,b;
    //     cin>>a>>b;
    //     int x=a,y=b;
    //     int ancestor=lca(a,b,depth,up);
    //     while(x!=ancestor){
    //         ans[x]++;
    //         x=parent[x];
    //     }
    //     while(y!=ancestor){
    //         ans[y]++;
    //         y=parent[y];
    //     }
    //     ans[ancestor]++;
    // }

    vector<int> cnt(n + 1, 0);

    while (q--) {
        int a, b;
        cin >> a >> b;
        int l = lca(a, b, depth, up);

        cnt[a]++;
        cnt[b]++;
        cnt[l]--;
        if (parent[l] != -1)
            cnt[parent[l]]--;
    }

    dfs2(1, -1, adj, cnt);

    for(int i=1;i<=n;i++){
        cout<<cnt[i]<<" ";
    }

    return 0;
}