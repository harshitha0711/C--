#include <iostream>
using namespace std;

class C1;
class C2;

class C1 {
    int status;
public:
    void set_status(int s) {
        status = s;
    }

    // Declare the friend function
    friend int table(C1 a, C2 b);
};

class C2 {
    int status;
public:
    void set_status(int s) {
        status = s;
    }
    friend int table(C1 a, C2 b);
};
int table(C1 a, C2 b) {
    if (a.status|| b.status)
        return 0;
    else
        return 1;
}

int main() {
    C1 x;
    C2 y;

    x.set_status(0);
    y.set_status(0);

    if (table(x, y))
        cout << "Resource is free\n";
    else
        cout << "Resource is in use\n";

    x.set_status(1);
    y.set_status(0);

    if (table(x, y))
        cout << "Resource is free\n";
    else
        cout << "Resource is in use\n";

    return 0;
}
