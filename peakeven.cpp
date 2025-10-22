#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        vector<ll> mx(n);
        mx[0] = a[0];
        for(int i = 1; i < n; i++){
            mx[i] = max(mx[i-1], a[i]);
        }

        // b[i] = initial value we can have freely = mx[i]
        vector<ll> b = mx;
        ll cost = 0;

        for(int i = 0; i + 1 < n; i++){
            if(i % 2 == 0){
                // need b[i] < b[i+1]
                if(b[i] >= b[i+1]){
                    // we either reduce b[i] to b[i+1] - 1
                    ll target_i = b[i+1] - 1;
                    ll cost_i = b[i] - target_i;
                    // or reduce b[i+1] downward so b[i] < new b[i+1]
                    ll target_ip1 = b[i] + 1;
                    ll cost_ip1 = b[i+1] - target_ip1;
                    if(cost_ip1 < cost_i){
                        cost += cost_ip1;
                        b[i+1] = target_ip1;
                    } else {
                        cost += cost_i;
                        b[i] = target_i;
                    }
                }
            } else {
                // i odd: need b[i] > b[i+1]
                if(b[i] <= b[i+1]){
                    // reduce b[i] to b[i+1] +1
                    ll target_i = b[i+1] + 1;
                    ll cost_i = b[i] - target_i; // careful: if target_i > b[i], cost_i would be negative → can't increase
                    if(target_i > b[i]){
                        // Cannot increase b[i], so we must reduce b[i+1]
                        ll target_ip1 = b[i] - 1;
                        ll cost_ip1 = b[i+1] - target_ip1;
                        cost += cost_ip1;
                        b[i+1] = target_ip1;
                    } else {
                        // Both options possible (rare), choose minimal cost
                        cost_i = b[i] - target_i;
                        ll target_ip1 = b[i] - 1;
                        ll cost_ip1 = b[i+1] - target_ip1;
                        if(cost_ip1 < cost_i){
                            cost += cost_ip1;
                            b[i+1] = target_ip1;
                        } else {
                            cost += cost_i;
                            b[i] = target_i;
                        }
                    }
                }
            }
        }

        cout << cost << "\n";
    }

    return 0;
}
