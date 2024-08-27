#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int PA, PB;
    double GA, GB, GAa, GBb;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int time = 0;
        cin >> PA >> PB;
        cin >> GA >> GB;
        GAa = GA/100;
        GBb = GB/100;


        while (PA <= PB && time <= 100) {
            PA += PA * GAa;
            PB += PB * GBb;
            time++;
        }
         if (time > 100) {
            cout << "Mais de 1 seculo." << endl;
        } else {
            cout << time << " anos." << endl;
        }
    }

    return 0;
}
