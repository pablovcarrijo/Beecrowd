#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, num;
    cin >> n;
    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        set<int> st;
        for(int j = 0; j < p; j++){
            cin >> num;
            st.insert(num);
        }
        int qnt = st.size();
        cout << qnt << endl;
    }

    return 0;
}