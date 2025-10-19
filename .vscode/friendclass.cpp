#include <iostream>
using namespace std;

class twoValues {
    int a;
    int b;

public:
    twoValues(int i, int j) { a = i; b = j; }
    friend class Min;  // Min class is friend of twoValues class
};

class Min {
public:
    int min(twoValues x);
};

int Min::min(twoValues x) {
    return (x.a < x.b) ? x.a : x.b;
}

int main() {
    twoValues ob(10, 20);
    Min m;
    cout << m.min(ob);
    return 0;
}
