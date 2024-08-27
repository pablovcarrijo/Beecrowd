#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, l, result;
    string phrase;
    cin >> n;
    for(int i = 0; i < n; ++i){
        result = 0;
        cin >> l;
        for(int j = 0; j < l; ++j){
            cin >> phrase;
            for(int k = 0; k < phrase.length(); ++k){
                result += (phrase[k] - 'A') + k + j;
            }
        }
        cout  << result << endl;
    }
    return 0;
}