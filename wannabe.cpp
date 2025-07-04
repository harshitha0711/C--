#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;  

    bool passed[101] = {false}; 

    int p;
    cin >> p; 
    for (int i = 0; i < p; i++) {
        int level;
        cin >> level;
        passed[level] = true; 
    }

    int q;
    cin >> q; 
    for (int i = 0; i < q; i++) {
        int level;
        cin >> level;
        passed[level] = true; 
    }

    
    bool allPassed = true;
    for (int i = 1; i <= n; i++) {
        if (!passed[i]) {
            allPassed = false;
            break;
        }
    }

    if (allPassed) {
        cout << "I become the guy." << endl;
    } else {
        cout << "Oh, my keyboard!" << endl;
    }

    return 0;
}
