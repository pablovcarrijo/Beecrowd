#include <bits/stdc++.h>

using namespace std;

int main(){

    string client, medico;
    cin >> client >> medico;
    int c = 0, m = 0;

    for(int i = 0; i < client.size(); i ++){
        if(client[i] == 'a' || client[i] == 'h'){
            c++;
        }
    }
    for(int i = 0; i < medico.size(); i++){
        if(medico[i] == 'a' || medico[i] == 'h'){
            m++;
        }
    }

    if(c >= m){
        cout << "go" << endl;
    }
    else if(c < m){
        cout << "no" << endl;
    }

    return 0;
}