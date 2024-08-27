#include <bits/stdc++.h>

using namespace std;

int main(){
    unsigned x, y, m, xi, yi;
    while(cin >> x >> y >> m){
        for(int i = 0; i < m; i++){
            xi = 0; yi = 0;
            cin >> xi >> yi;
            if((xi <= x && yi <= y) || (yi <= x && xi <= y)){
                cout << "Sim" << endl;
            }
            else {
                cout << "Não" << endl;
            }
        }
    
    }
    return 0;
}