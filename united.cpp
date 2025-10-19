#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        long long mx = *max_element(a.begin(), a.end());
        vector<long long> b, c;

        for (auto x : a) {
            if (x == mx) c.push_back(x);
            else b.push_back(x);
        }

        if (b.empty()) {
            cout << -1 << "\n";
        } else {
            cout << b.size() << " " << c.size() << "\n";
            for (auto x : b) cout << x << " ";
            cout << "\n";
            for (auto x : c) cout << x << " ";
            cout << "\n";
        }
    }

    return 0;
}
