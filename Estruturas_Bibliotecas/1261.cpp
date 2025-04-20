#include <bits/stdc++.h>
#include <string>
#include <map>

using namespace std;

int main(){
 
    int m, n, salarioTemp, salario;
    map<string, int> profissao;
    string description, profTemp;

    
    cin >> m >> n;
    
    for(int i = 0; i < m; i++){

        cin >> profTemp;
        cin >> salarioTemp;

        profissao.insert({profTemp, salarioTemp});
    }
    
    for(int i = 0; i < n; i++){
       salario = 0;
        
       while(cin >> description && description != "."){
            if(profissao.count(description)){
                salario += profissao.at(description);
            }
       }

       cout << salario << endl;

    }
}