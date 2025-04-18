#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char pais[50];
    char mensagem[50];
}Natal;


Natal mensagens[24] = {  
    {"alemanha", "Frohliche Weihnachten!"},
    {"antardida", "Merry Christmas!"},
    {"argentina", "Feliz Navidad!"},
    {"australia", "Merry Christmas!"},
    {"austria", "Frohe Weihnacht!"},
    {"belgica", "Zalig Kerstfeest!"},
    {"brasil", "Feliz Natal!"},
    {"canada", "Merry Christmas!"},
    {"chile", "Feliz Navidad!"},
    {"coreia", "Chuk Sung Tan!"},
    {"espanha", "Feliz Navidad!"},
    {"estados-unidos", "Merry Christmas!"},
    {"grecia", "Kala Christougena!"},
    {"inglaterra", "Merry Christmas!"},
    {"irlanda", "Nollaig Shona Dhuit!"},
    {"italia", "Buon Natale!"},
    {"japao", "Merii Kurisumasu!"},
    {"libia", "Buon Natale!"},
    {"marrocos", "Milad Mubarak!"},
    {"mexico", "Feliz Navidad!"},
    {"portugal", "Feliz Natal!"},
    {"siria", "Milad Mubarak!"},
    {"suecia", "God Jul!"},
    {"turquia", "Mutlu Noeller"}
};

int buscaBinaria(Natal *mensagem, int tamanho, char *chave){
    int esquerda = 0, direita = tamanho -1;

    while (esquerda <= direita){
        int meio = (direita + esquerda) / 2;

        int  comparacao = strcmp(chave, mensagem[meio].pais);

        if(comparacao == 0){
            return meio;
        }
        else if(comparacao < 0){
            direita = meio - 1;
        }
        else{
            esquerda = meio + 1;
        }
    }
    return -1;
}

int main() {
    int totalPaises = sizeof(mensagens) / sizeof(mensagens[0]);
    char paisBuscado[50];

    while (scanf(" %[^\n]", paisBuscado) != EOF) { // Lendo entrada corretamente
        int indice = buscaBinaria(mensagens, totalPaises, paisBuscado);
        if (indice != -1) {
            printf("%s\n", mensagens[indice].mensagem);
        } else {
            printf("--- NOT FOUND ---\n");
        }
    }

    return 0;
}
