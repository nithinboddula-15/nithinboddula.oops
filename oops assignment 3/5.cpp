#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n = 2;
    vector<vector<int>> pre = {{1,0}};

    vector<int> indeg(n,0);
    vector<vector<int>> adj(n);

    for(auto &p : pre){
        adj[p[1]].push_back(p[0]);
        indeg[p[0]]++;
    }

    queue<int> q;
    for(int i=0;i<n;i++)
        if(indeg[i]==0) q.push(i);

    int cnt=0;

    while(!q.empty()){
        int u=q.front(); q.pop();
        cnt++;

        for(int v : adj[u]){
            indeg[v]--;
            if(indeg[v]==0)
                q.push(v);
        }
    }

    cout << (cnt==n ? "Possible" : "Not Possible");
}
