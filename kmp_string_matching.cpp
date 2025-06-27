#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> build_lps(const string &pat) {
    int n = pat.size();
    vector<int> lps(n);
    for (int i = 1, len = 0; i < n;) {
        if (pat[i] == pat[len]) {
            lps[i++] = ++len;
        } else if (len) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}

void kmp_search(const string &text, const string &pat) {
    vector<int> lps = build_lps(pat);
    int i = 0, j = 0;
    while (i < text.size()) {
        if (text[i] == pat[j]) {
            i++;
            j++;
        }

        if (j == pat.size()) {
            cout << "Pattern found at index: " << i - j << "\n";
            j = lps[j - 1];
        } else if (i < text.size() && text[i] != pat[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    string text, pattern;
    cin >> text >> pattern;
    kmp_search(text, pattern);
}
