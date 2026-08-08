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
#include <climits>
using namespace std;

#define int long long

const long long INF=1e18;

signed main(){

    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> adj(n+1);

    while(m--){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
    }

    vector<vector<int>> dist(n+1,vector<int>(2,INF));

    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,
                    greater<tuple<int,int,int>>> pq;

    dist[1][0]=0;
    pq.push({0,1,0});

    while(!pq.empty()){

        auto [d,node,used]=pq.top();
        pq.pop();

        if(d!=dist[node][used]) continue;
        for(auto [next,w]:adj[node]){

            if(used==0){
                if(dist[next][0]>d+w){
                    dist[next][0]=d+w;
                    pq.push({dist[next][0],next,0});
                }

                if(dist[next][1]>d+w/2){
                    dist[next][1]=d+w/2;
                    pq.push({dist[next][1],next,1});
                }
            }
            else{

                if(dist[next][1]>d+w){
                    dist[next][1]=d+w;
                    pq.push({dist[next][1],next,1});
                }
            }
        }
    }

    cout<<dist[n][1];
}