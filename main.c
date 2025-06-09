#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


typedef struct no {
    char nome[50];
    char CPF[15];
    struct no *proximo;
} No;

typedef struct{
    No *inicio;
    No *fim;
    int tam;
} ListaC;

void Criar(ListaC *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}
void InserirInicio(ListaC *lista, const char* nome, const char* cpf){
    No *novoNo = malloc(sizeof(No));

    if(novoNo ){
        strcpy(novoNo->nome, nome);
        strcpy(novoNo->CPF, cpf);
        novoNo->proximo = lista->inicio;
        lista->inicio = novoNo;

        if(lista->fim == NULL){
            lista->fim = novoNo;
        }
        lista->fim->proximo = lista->inicio;
        lista->tam++;
    }
    else{
        printf("\nErro de alocacao");
    }
}

void InserirFim(ListaC *lista, const char* nome, const char* cpf){
    No *aux, *novoNo = malloc(sizeof(No));

    if(novoNo){
        strcpy(novoNo->nome, nome);
        strcpy(novoNo->CPF, cpf);
        if(lista->inicio ==NULL){
            lista->inicio = novoNo;
            lista->fim = novoNo;
            lista->fim->proximo = lista->inicio;
        }else{
            lista->fim->proximo = novoNo;
            lista->fim = novoNo;
            lista->fim->proximo = lista->inicio;
        }
        lista->tam++;
    }
    else{
        printf("\nErro de alocacao");
    }
}


void ImprimirListaCircular(ListaC *lista){
    if(lista->inicio ==NULL){
        printf("\nErro: Vazio");
        return;
    }
    
    No *noAux = lista->inicio;
    printf("\n\tLista tam %d: ", lista->tam);
    do{
        printf("Nome: %s || CPF: %s ->", noAux->nome, noAux->CPF);
        noAux = noAux->proximo;

    }while(noAux != lista->inicio);
    
    printf("\n\n");
}


int main(){ 
    srand(time(NULL));

    int tam;

    printf("\nInsira o Tamanho da Lista");
    scanf("%d", &tam);

    return 0;
}
