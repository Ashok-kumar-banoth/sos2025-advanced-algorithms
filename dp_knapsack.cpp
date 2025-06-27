#include <iostream>
#include<vector>
using namespace std;
#define int long long

int32_t main() {
    int n, w;
    cin >> n >> w;
    vector<int> weight(n), value(n);
    for (int i = 0; i < n; ++i) cin >> weight[i];
    for (int i = 0; i < n; ++i) cin >> value[i];
    
    vector<int> dp(w+1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = w; j >= weight[i]; --j) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[w] << "\n";
}
