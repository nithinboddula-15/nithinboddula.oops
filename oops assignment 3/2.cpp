#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int V = 5;
    vector<vector<pair<int,int>>> g(V);

    g[0] = {{1,2},{2,4}};
    g[1] = {{2,1},{3,7}};
    g[2] = {{4,3}};

    vector<int> dist(V, 1000000000);
    dist[0] = 0;

    priority_queue<pair<int,int>, 
        vector<pair<int,int>>, 
        greater<pair<int,int>>> pq;

    pq.push({0,0});

    while(!pq.empty()){
        auto temp = pq.top(); 
        pq.pop();
        int d = temp.first;
        int u = temp.second;

        for(auto &p : g[u]){
            int v = p.first;
            int w = p.second;

            if(d + w < dist[v]){
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    for(int x : dist) cout << x << " ";
}
