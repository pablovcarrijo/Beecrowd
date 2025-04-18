#include <stdio.h>
#include <stdlib.h>

typedef struct st_no{
    int valor;
    struct st_no *esquerda;
    struct st_no *direita;
    
} Arvore;

typedef struct{
    Arvore *raiz;
} Raiz;

void inicializaArvore(Raiz *arvore){
    arvore->raiz = NULL;
}

void adicionarValor(Raiz *arvore, int valor){


    if(arvore->raiz == NULL){
        Arvore *novo = (Arvore*)malloc(sizeof(Arvore));
        novo->valor = valor;
        novo->direita = NULL;
        novo->esquerda = NULL;
        arvore->raiz = novo;
    }
    else{
        if(arvore->raiz->valor < valor){
            adicionarValor(&(arvore->raiz->direita), valor);
        }
        else{
            adicionarValor(&(arvore->raiz->esquerda), valor);
        }
    }

}

void imprimirPreOrdem(Arvore *no){
    if(no != NULL){
        printf(" %d", no->valor);
        imprimirPreOrdem(no->esquerda);
        imprimirPreOrdem(no->direita);
    }
}

void imprimirPosOrdem(Arvore *no){
    if(no != NULL){
        imprimirPosOrdem(no->esquerda);
        imprimirPosOrdem(no->direita);
        printf(" %d", no->valor);
    }
}

void imprimirIn(Arvore *no){
    if(no != NULL){
        imprimirIn(no->esquerda);
        printf(" %d", no->valor);
        imprimirIn(no->direita);
    }
}

int main(){
    int n, x, value;
    Raiz *minhaArvore = (Raiz*)malloc(sizeof(Raiz));
    
    if(minhaArvore == NULL){
        printf("Erro ao alocar memoria");
        return 1;
    }
    
    inicializaArvore(minhaArvore);

    scanf("%d%*c", &n);

    for(int i = 0; i < n; i++){
        scanf("%d%*c", &x);
    
        for(int j = 0; j < x; j++){
            scanf("%d%*c", &value);
            adicionarValor(minhaArvore, value);
        }

        // Imprimir a árvore nas três ordens
        printf("Pre.:");
        imprimirPreOrdem(minhaArvore->raiz);
        printf("\n");
 
        printf("In.:");
        imprimirIn(minhaArvore->raiz);
        printf("\n");
 
        printf("Post.:");
        imprimirPosOrdem(minhaArvore->raiz);
        printf("\n\n");

    }

    return 0;
}