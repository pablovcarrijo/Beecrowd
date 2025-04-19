#include <bits/stdc++.h>
#include <string.h>
#include <vector>

using namespace std;

int main(){
    
    int n, flag1, flag2;
    string dieta;
    string auxiliar;
    vector<char> dietaVector;
    
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        
        dietaVector.clear();

        flag1 = 1;
        flag2 = 1;

        getline(cin, dieta);
        for(char die : dieta){
            dietaVector.push_back(die);
        }

        getline(cin, auxiliar);
        for(char aux : auxiliar){
            flag1 = 0;
            for(int i = 0; i < dietaVector.size(); i++){
                if(aux == dietaVector.at(i)){
                    dietaVector.erase(dietaVector.begin() + i);
                    flag1 = 1;
                    break;
                }
            }
            if(flag1 == 0){
                break;
            }
        }

        getline(cin, auxiliar);
        for(char aux : auxiliar){
            flag2 = 0;
            for(int i = 0; i < dietaVector.size(); i++){
                if(aux == dietaVector.at(i)){
                    dietaVector.erase(dietaVector.begin() + i);
                    flag2 = 1;
                    break;
                }
            }
            if(flag2 == 0){
                break;
            }
        }

        if(flag1 == 0 || flag2 == 0){
            cout << "CHEATER" << endl;
        }
        else{   
            sort(dietaVector.begin(), dietaVector.end());
            for(auto die : dietaVector){
                cout << die;
            }
            cout << endl;
        }

    }

}