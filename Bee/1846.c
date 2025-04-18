#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *unidades[] = {"zero", "um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", 
                          "nove", "dez", "onze", "doze", "treze", "quatorze", "quinze", "dezesseis",
                          "dezessete", "dezoito", "dezenove"};

const char *dezenas[] = {"", "", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta",
                         "noventa"};

const char *centenas[] = {"", "cento", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seiscentos",
                          "setecentos", "oitocentos", "novecentos"};

const char *mil = "mil";

void numeroPorExtenso(int n, char *extenso) {
    if (n == 0) { 
        strcpy(extenso, "zero");
        return;
    }

    int partes[4] = {0};
    partes[0] = n / 1000; 
    n %= 1000;
    partes[1] = n / 100; 
    n %= 100;
    partes[2] = n / 10; 
    partes[3] = n % 10; 

    extenso[0] = '\0'; 
    int tem_anterior = 0;  

    if (partes[0] > 0) {
        if (partes[0] == 1) {
            strcat(extenso, mil);
        } else {
            strcat(extenso, unidades[partes[0]]);
            strcat(extenso, " ");
            strcat(extenso, mil);
        }
        tem_anterior = 1;
    }

    if (partes[1] > 0) {
        if (tem_anterior) strcat(extenso, " e ");
        if (partes[1] == 1 && partes[2] == 0 && partes[3] == 0) {
            strcat(extenso, "cem");
        } else {
            strcat(extenso, centenas[partes[1]]);
        }
        tem_anterior = 1;
    }

    if (partes[2] > 1) {
        if (tem_anterior) strcat(extenso, " e ");
        strcat(extenso, dezenas[partes[2]]);
        if (partes[3] > 0) {
            strcat(extenso, " e ");
            strcat(extenso, unidades[partes[3]]);
        }
    } else if (partes[2] == 1) {
        if (tem_anterior) strcat(extenso, " e ");
        strcat(extenso, unidades[partes[2] * 10 + partes[3]]);
    } else if (partes[3] > 0) {
        if (tem_anterior) strcat(extenso, " e ");
        strcat(extenso, unidades[partes[3]]);
    }
}

int main() {
    char extenso[1000];  // Aumentando o tamanho do buffer
    int n;
    
    // Loop até o final da entrada
    while (scanf("%d", &n) != EOF) {  
        numeroPorExtenso(n, extenso);
        printf("%s\n", extenso);
    }

    return 0;
}
