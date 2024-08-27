#include <bits/stdc++.h>

using namespace std;

int main(){

    map<int, int> v;

    int n, x, y, j = 1;
    double sumx = 0.0, sumy = 0.0, result = 0.0;

    while(cin >> n && n != 0){
        v.clear();
        for(int i = 0; i < n; i++){
            cin >> x >> y;
            sumx += x;
            sumy += y;
            if(x != 0){
                result = y / x;
                v[result] += x;
            }
        }

        map<int, int>::iterator it;
        cout << "Cidade# " << j << ":" << endl;
        for(it = v.begin(); it != v.end(); it++){
            cout << it->second << "-" << it->first << " ";
        }

        j++;
        double media = sumy / sumx;

        cout << endl;
        cout << "Consumo medio: " << fixed << setprecision(2) << trunc(media * 100)/100 << " m3." << endl;

        cout << endl;

        media = 0.0; 
        sumy = 0.0;
        sumx = 0.0;
    }

    return 0;

}