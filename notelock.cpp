#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<int> protect(n, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                bool canBeChanged = true;
                for (int j = max(0, i - k + 1); j < i; j++) {
                    if (s[j] == '1') {
                        canBeChanged = false;
                        break;
                    }
                }
                if (canBeChanged) {
                  
                    if (!protect[i]) {
                        ans++;
                        protect[i] = 1;
                        for (int j = i + 1; j < min(n, i + k); j++) {
                            protect[j] = 1;
                        }
                    }
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
