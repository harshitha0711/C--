#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            cout << 0 << "\n";
            return 0;
        }
    }

    vector<int> abs_vals(n);
    for (int i = 0; i < n; i++) {
        abs_vals[i] = abs(a[i]);
    }

    sort(abs_vals.begin(), abs_vals.end());

    cout << abs_vals[0] << "\n";

    return 0;
}
