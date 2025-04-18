#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int N, casas;
    char frase[51];

    scanf("%d%*c", &N);
    for(int i = 0; i < N; i++){
        scanf("%s", frase);
        scanf("%d%*c", &casas);

        for(int j = 0; j < strlen(frase); j++){
            if((int)frase[j] - casas >= 65){
                frase[j] -= casas;  
            }
            else {
                frase[j] += 26 - casas;
            }
        }
        printf("%s\n", frase);

    }
}