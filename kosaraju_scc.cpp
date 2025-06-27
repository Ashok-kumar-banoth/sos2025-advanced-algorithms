#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj, rev;
vector<bool> vis;
vector<int> order, component;

void dfs1(int node) {
    vis[node] = true;
    for (int v : adj[node])
        if (!vis[v]) dfs1(v);
    order.push_back(node);
}

void dfs2(int node) {
    vis[node] = true;
    component.push_back(node);
    for (int v : rev[node])
        if (!vis[v]) dfs2(v);
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    rev.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }

    vis.assign(n + 1, false);
    for (int i = 1; i <= n; ++i)
        if (!vis[i]) dfs1(i);

    vis.assign(n + 1, false);
    reverse(order.begin(), order.end());
    for (int u : order) {
        if (!vis[u]) {
            component.clear();
            dfs2(u);
            for (int x : component)
                cout << x << " ";
            cout << "\n";
        }
    }
}
