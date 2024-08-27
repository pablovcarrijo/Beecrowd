#include <bits/stdc++.h>
using namespace std;

int main() {
    string nx;
    char n;
    while (cin >> n >> nx && n != '0' && nx != "0") {
        bool leadingZero = true;
        for (char c : nx) {
            if (c != n) {
                if (c != '0' || !leadingZero) {
                    cout << c;
                    leadingZero = false;
                }
            }
        }
        if (leadingZero) {
            cout << '0';
        }
        cout << endl;
    }
    return 0;
}
