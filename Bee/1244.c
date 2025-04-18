#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void separa(char *frase){
    char *palavra[2250];
    int n = 0;

    char *token = strtok(frase,  " ");
    while(token){
        palavra[n++] = token;
        token = strtok(NULL, " ");
    }

    orderna(palavra, n);

    for(int i = 0; i < n; i++){
        printf("%s", palavra[i]);
        if(i < n - 1){
            printf(" ");
        }
    }
    printf("\n");


}

void orderna(char *frase[], int n){
    char *temp;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(strlen(frase[j]) < strlen(frase[j + 1])){
                temp = frase[j];
                frase[j] = frase[j + 1];
                frase[j + 1] = temp;
            }
        }
    }
}

int main(){
    char frase[2250];
    int n;
    scanf("%d%*c", &n);

    for(int i = 0; i < n; i++){
        fgets(frase, sizeof(frase), stdin);
        frase[strcspn(frase, "\n")] = '\0';
        separa(frase);
    }

    return 0;
}