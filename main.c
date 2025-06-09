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
    No *fim;
    int tam;
} ListaC;

void Criar(ListaC *lista){
    lista->fim = NULL;
    lista->tam = 0;
}
void InserirInicio(ListaC *lista, const char* nome, const char* cpf){
    No *novoNo = malloc(sizeof(No));

    if(novoNo){
        strcpy(novoNo->nome, nome);
        strcpy(novoNo->CPF, cpf);

        if(lista->fim == NULL){
            lista->fim = novoNo;
            novoNo->proximo = novoNo;
        }else{
            novoNo->proximo = lista->fim->proximo;
            lista->fim->proximo = novoNo;
        }
        lista->tam++;
    }
    else{
        printf("\nErro de alocacao");
    }
}

void Sortear( ListaC *lista, int num){

}

void removerQualquer(ListaC *lista, int N){
    if(lista->fim ==NULL || N < 0 || N >= lista->tam){
        printf("\nVazio");
        return;
    }
    No *remover = NULL;
    if(lista->tam == 1){
        remover = lista->fim;
        lista->fim = NULL;
    }else{
        No *anterior;
        if(N == 0){
            anterior = lista->fim;
        }else{
            anterior = BuscarElementoIndice(lista, N - 1);
        }
        remover = anterior->proximo;
        anterior->proximo = remover->proximo;
        if(remover == lista->fim){
            lista->fim = anterior;
        }
    }
    printf("Nome: %s, CPF: %s\n", remover->nome, remover->CPF);
    free(remover);
    lista->tam--;
}

void BuscarElementoIndice(ListaC *lista, int N){
    if(lista->fim ==NULL){
        printf("\nVazio");
        return;
    }
    No *aux = lista->fim->proximo;
    for(int i = 0; i < N; i++){
        aux = aux->proximo;
    }
    return aux;
}

void InserirFim(ListaC *lista, const char* nome, const char* cpf){
    No *aux, *novoNo = malloc(sizeof(No));

    if(novoNo){
        strcpy(novoNo->nome, nome);
        strcpy(novoNo->CPF, cpf);
        if(lista->fim ==NULL){
            lista->fim = novoNo;
            novoNo->proximo = novoNo;
        }else{
            novoNo->proximo = lista->fim->proximo;
            lista->fim->proximo = novoNo;
            lista->fim = novoNo;
        }
        lista->tam++;
    }
    else{
        printf("\nErro de alocacao");
    }
}


void ImprimirListaCircular(ListaC *lista){
    if(lista->fim ==NULL){
        printf("\nErro: Vazio");
        return;
    }
    
    No *noAux = lista->fim->proximo;
    printf("\n\tLista tam %d: ", lista->tam);
    do{
        printf("Nome: %s || CPF: %s ->", noAux->nome, noAux->CPF);
        noAux = noAux->proximo;

    }while(noAux != lista->fim->proximo);
    
    printf("\n\n");
}


int main(){ 
    srand(time(NULL));

    int tam;
    ListaC Lista;
    Criar(&Lista);

    printf("\nInsira a Quantidade de Participantes");
    scanf("%d", &tam);

    for(int i = 0; i < tam -1; i++){
                
    }

    return 0;
}
