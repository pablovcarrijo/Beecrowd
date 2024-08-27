#include <bits/stdc++.h>

using namespace std;

int main(){

    int dia, horas, minutos, segundos;
    int dia2, horas2, minutos2, segundos2;
    string temp;

    cin >> temp >> dia;
    cin >> horas >> temp >> minutos >> temp >> segundos;

    cin >> temp >> dia2;
    cin >> horas2 >> temp >> minutos2 >> temp >> segundos2;

    segundos = segundos2 - segundos;
    minutos = minutos2 - minutos;
    horas = horas2 - horas;
    dia = dia2 - dia;

    if(segundos < 0){
        segundos+= 60;
        minutos--;
    }
    if(minutos < 0){
        minutos+= 60;
        horas--;
    }
    if(horas < 0){
        horas += 24;
        dia--;
    }

    cout << dia << " dia(s)" << endl;
    cout << horas << " hora(s)" << endl;
    cout << minutos << " minuto(s)" << endl;
    cout << segundos << " segundo(s)" << endl;

    return 0;

}