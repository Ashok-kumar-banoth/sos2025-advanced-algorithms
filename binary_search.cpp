#include <iostream>
#include<vector>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    
    int low = 0, high = n-1, ans = -1;
    while (low <= high) {
        int mid = (low + high)/2;
        if (a[mid] == target) {
            ans = mid;
            break;
        } else if (a[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout << (ans != -1 ? "Found" : "Not Found");
}
