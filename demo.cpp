#include <iostream>
using namespace std;

int main() {
    int limit;

    cout << "Enter the upper limit: ";
    cin >> limit;

    cout << "Odd numbers from 1 to " << limit << " are:\n";

    for (int i = 1; i <= limit; i++) {
        if (i % 2 != 0) {
            cout << i << " ";
        }
    }

    cout << endl;
    return 0;
}
