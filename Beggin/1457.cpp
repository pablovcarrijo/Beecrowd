#include <bits/stdc++.h>
using namespace std;

long long factorial(int n, int k){
    long long fat = n;
    while(n-k > 1){
        fat *= (n-k);
        n -= k;
    }
    return fat;
}

int main(){


    int t;
    cin >> t;
    cin.ignore();

    for(int i = 0; i < t; i++){
            string nStr;
            getline(cin, nStr);

            int k = 0;
            int nstrSize = nStr.size() - 1;

            while(nstrSize >= 0 && nStr[nstrSize] == '!'){
                k++;
                nstrSize--;
            }

            int n = stoi(nStr.substr(0, nstrSize+1));

            long long result = factorial(n, k);
            cout << result << "\n";

    }

}