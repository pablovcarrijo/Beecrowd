#include <bits/stdc++.h>
#include <string.h>
#include <map>

using namespace std;

int main(){
    int n, count;
    double quantity = 1;

    
    string name;
    map<string, double> arvores;
    
    cin >> n;
    cin.ignore();
    cin.ignore();
    cout << fixed << setprecision(4);

    
    for(int i = 0; i < n; i++){
        arvores.clear();
        count = 0;

        while(getline(cin, name)){
            if(name.empty()){
                break;
            }
            if(arvores.count(name)){
                arvores[name] = arvores[name] + 1;
            }
            else{
                arvores.insert({name, quantity});
            }
            count ++;
        }
        
        for(auto arvore : arvores){
            arvores.at(arvore.first) = (arvore.second / count) * 100;
        }

        for(auto arvore : arvores){
            cout << arvore.first << " " << arvore.second << endl;
        }

        if(i != n-1) cout << endl;
    }

}