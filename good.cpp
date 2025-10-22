#include <bits/stdc++.h>
using namespace std;

const int MAX_A = 200005;
int spf[MAX_A];

void computeSPF() {
    for (int i = 2; i < MAX_A; i++) spf[i] = 0;
    for (int i = 2; i < MAX_A; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            for (long long j = (long long)i * i; j < MAX_A; j += i)
                if (spf[j] == 0) spf[j] = i;
        }
    }
}

vector<int> factorize(int x) {
    vector<int> factors;
    while (x > 1) {
        int p = spf[x];
        factors.push_back(p);
        while (x % p == 0) x /= p;
    }
    return factors;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    computeSPF();

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;

        unordered_map<int, vector<pair<int,int>>> primeMap;

        int answer = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int inc = 0; inc <= 2; inc++) {
                int val = a[i] + inc;
                vector<int> primes = factorize(val);

                sort(primes.begin(), primes.end());
                primes.erase(unique(primes.begin(), primes.end()), primes.end());

                for (int p : primes) {
                    auto &vec = primeMap[p];
                    int cost = inc;

                    for (auto &[c, idx] : vec) {
                        if (idx != i) {
                            answer = min(answer, cost + c);
                        }
                    }

                    vec.emplace_back(cost, i);
                    sort(vec.begin(), vec.end());
                    if ((int)vec.size() > 2) vec.resize(2);
                }
            }
        }

        if (answer == INT_MAX) answer = 2;

        cout << answer << "\n";
    }
    return 0;
}
