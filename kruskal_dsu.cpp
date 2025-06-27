#include <iostream>
#include <vector>
#include <algorithm> 
#include <numeric>  
using namespace std;
#define int long long

struct Edge {
    int u, v, w;
    bool operator<(const Edge &e) const {
        return w < e.w;
    }
};

int find(int x, vector<int> &par) {
    return (par[x] == x ? x : par[x] = find(par[x], par));
}

bool unite(int a, int b, vector<int> &par) {
    a = find(a, par);
    b = find(b, par);
    if (a == b) return false;
    par[b] = a;
    return true;
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end());             // ✅ sort works now
    vector<int> par(n + 1);
    iota(par.begin(), par.end(), 0);              // ✅ iota works now

    int totalCost = 0;
    for (auto &e : edges) {
        if (unite(e.u, e.v, par)) {
            totalCost += e.w;
        }
    }

    cout << totalCost << "\n";
}
