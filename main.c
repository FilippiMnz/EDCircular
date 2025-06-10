#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct no {
    char nome[50];
    char CPF[15];
    struct no *proximo;
} No;

typedef struct {
    No *fim;
    int tam;
} ListaC;

void Criar(ListaC *lista){
    lista->fim = NULL;
    lista->tam = 0;
}

void InserirFim(ListaC *lista, const char* nome, const char* cpf){
    No *novoNo = malloc(sizeof(No));

    if(novoNo){
        strcpy(novoNo->nome, nome);
        strcpy(novoNo->CPF, cpf);
        if(lista->fim == NULL){
            lista->fim = novoNo;
            novoNo->proximo = novoNo;
        } else {
            novoNo->proximo = lista->fim->proximo;
            lista->fim->proximo = novoNo;
            lista->fim = novoNo;
        }
        lista->tam++;
    } else {
        printf("\nErro de alocacao");
    }
}

No* BuscarElementoIndice(ListaC *lista, int N){
    if(lista->fim == NULL){
        printf("\nVazio");
        return NULL;
    }
    No *aux = lista->fim->proximo;
    for(int i = 0; i < N; i++){
        aux = aux->proximo;
    }
    return aux;
}

void removerQualquer(ListaC *lista, int N){
    if(lista->fim == NULL || N < 0 || N >= lista->tam){
        printf("\nVazio");
        return;
    }
    No *remover = NULL;

    if(lista->tam == 1){
        remover = lista->fim;
        lista->fim = NULL;
    } else {
        No *anterior = BuscarElementoIndice(lista, (N + lista->tam - 1) % lista->tam);
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

void ImprimirListaCircular(ListaC *lista){
    if(lista->fim == NULL){
        printf("\nErro: Vazio");
        return;
    }

    No *noAux = lista->fim->proximo;
    printf("\n\tLista tam %d: ", lista->tam);
    do{
        printf("Nome: %s || CPF: %s || ", noAux->nome, noAux->CPF);
        noAux = noAux->proximo;
    } while(noAux != lista->fim->proximo);

    printf("\n\n");
}

void Liberar(ListaC *lista){
    while(lista->tam > 0){
        removerQualquer(lista, 0);
    }
    printf("Lista Finalizada");
}

void sorteio(ListaC *lista) {
    static No *alvo = NULL;

    if (lista->tam == 0) {
        printf("\nLista Vazia\n");
        return;
    }
    if (alvo == NULL || alvo->proximo == NULL) {
        alvo = lista->fim;
    }

    int m = (rand() % lista->tam) + 1;

    printf("\nNúmero sorteado: %d\n", m);
    printf("\nContagem começando por: %s\n", alvo->proximo->nome);

    for (int i = 0; i < m - 1; i++) {
        alvo = alvo->proximo;
    }

    No *remover = alvo->proximo;

    printf("\nEliminado: %s\n", remover->nome);

    alvo->proximo = remover->proximo;
    if (remover == lista->fim) {
        lista->fim = alvo;
    }

    free(remover);
    lista->tam--;

    ImprimirListaCircular(lista);

    if (lista->tam == 1) {
        printf("\nTemos um VENCEDOR!\n");
        printf("Nome: %s || CPF: %s\n", lista->fim->nome, lista->fim->CPF);
        free(lista->fim);
        lista->fim = NULL;
        lista->tam = 0;
        alvo = NULL;
    }
}

int main(){
    srand(time(NULL));
    int opcao;
    char nome[50];
    char cpf[15];
    ListaC lista;
    Criar(&lista);

    do {
        printf("1- Adicionar Participante\n");
        printf("2- Listar Participantes Atuais\n");
        printf("3- REALIZAR SORTEIO \n");
        printf("4- Sair\n");
        printf("5- Popular Lista\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("\nDigite o nome: ");
                scanf(" %49[^\n]", nome);
                printf("Digite o CPF: ");
                scanf("%14s", cpf);
                InserirFim(&lista, nome, cpf);
                break;
            case 2:
                ImprimirListaCircular(&lista);
                break;
            case 3:
                sorteio(&lista);
                break;
            case 4:
                if(lista.tam > 0) {
                   Liberar(&lista);
                } else {
                   printf("\nGoodbyeee\n");
                }
                break;
            case 5:
                printf("Populando Lista");
                InserirFim(&lista, "ED", "369.872.530-48");
                InserirFim(&lista, "AL", "633.983.740-93");
                InserirFim(&lista, "MUSTANG", "566.329.180-69");
                InserirFim(&lista, "GREED", "069.033.260-22");
                InserirFim(&lista, "HUGHES", "432.678.030-47");
            default:
                printf("\ninvalido\n");
        }
    } while(opcao != 4);

    return 0;
}
