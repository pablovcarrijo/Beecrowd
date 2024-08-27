#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    cin.ignore();
    string text;
    char aux;

    for(int i = 0; i < n; i++){
        getline(cin, text);
        for(int j = 0; j < text.length(); j++){
            if(isalpha(text[j])){
                text[j] += 3;
            }
        }

        for(int k = 0; k < (text.length()/2); ++k){
            aux = text[k];
            text[k] = text[text.length() - 1 - k];
            text[text.length() - 1 - k] = aux; 
        }

        for(int i = (text.length()/2); i < text.length(); i++){
            --text[i];
        }
    
        cout << text << endl;

    }

    return 0;
}