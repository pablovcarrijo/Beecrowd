#include <bits/stdc++.h>

using namespace std;

int main(){

    int a, b, c, x, y, z;
    int aux;

    cin >> a >> b >> c;

    x = a;
    y = b;
    z = c;

    if(a > b){
        aux = a;
        a = b;
        b = aux;
    }
    if(b > c){
        aux = b;
        b = c;
        c = aux;
    }
    if(a > b){
        aux = a;
        a = b;
        b = aux;
    }

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << endl;
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;

}

