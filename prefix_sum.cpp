#include <iostream>
#include <vector>
using namespace std;
#define int long long

int32_t main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1, 0), prefix(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        prefix[i] = prefix[i-1] + a[i];
    }
    while(q--) {
        int l, r; cin >> l >> r;
        cout << prefix[r] - prefix[l-1] << "\n";
    }
}
