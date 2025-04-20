#include <bits/stdc++.h>
#include <string>
#include <map>

using namespace std;

int main(){
    int n, m, p, quantity;
    string nomeTemp;
    double precoTemp, total;
    
    map<string, double> frutas;
    
    cout << fixed << setprecision(2);
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> m;

        frutas.clear();

        for(int j = 0; j < m; j++){
            cin >> nomeTemp;
            cin >> precoTemp;

            frutas.insert({nomeTemp, precoTemp});

        }

        cin >> p;
        total = 0;

        for(int j = 0; j < p; j++){
            cin >> nomeTemp;
            cin >> quantity;
            if(frutas.count(nomeTemp)){
                total += frutas.at(nomeTemp) * quantity;
            }
        }

        cout << "R$ " << total << endl;

    }

}