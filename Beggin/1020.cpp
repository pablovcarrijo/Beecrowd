#include <bits/stdc++.h>

using namespace std;

int main(){

    int dias;
    cin >> dias;

    int ano = dias / 365;
    dias = dias - (ano * 365);

    int mes = dias / 30;
    dias = dias - (mes * 30);

    cout << ano << " ano(s)" << endl;
    cout << mes << " mes(es)" << endl;
    cout << dias << " dia(s)" << endl;

}