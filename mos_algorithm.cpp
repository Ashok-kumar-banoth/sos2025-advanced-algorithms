#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Query {
    int l, r, idx;
    bool operator<(const Query &q) const {
        int block = 320;  // sqrt(N), adjust accordingly
        if (l / block != q.l / block)
            return l < q.l;
        return r < q.r;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].idx = i;
    }

    sort(queries.begin(), queries.end());

    vector<int> freq(1e6 + 5, 0), ans(q);
    int curr_l = 0, curr_r = -1, curr_ans = 0;

    auto add = [&](int x) {
        freq[x]++;
        if (freq[x] == 1) curr_ans++;
    };

    auto remove = [&](int x) {
        freq[x]--;
        if (freq[x] == 0) curr_ans--;
    };

    for (const auto &query : queries) {
        while (curr_r < query.r) add(a[++curr_r]);
        while (curr_l > query.l) add(a[--curr_l]);
        while (curr_r > query.r) remove(a[curr_r--]);
        while (curr_l < query.l) remove(a[curr_l++]);
        ans[query.idx] = curr_ans;
    }

    for (int x : ans)
        cout << x << "\n";
}
