#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char palavra[50];
    char definicao[200];
    struct Node* esq;
    struct Node* dir;
} Node;

Node* criarNo(const char* palavra, const char* definicao) {
    Node* novo = (Node*)malloc(sizeof(Node));
    strcpy(novo->palavra, palavra);
    strcpy(novo->definicao, definicao);
    novo->esq = novo->dir = NULL;
    return novo;
}

Node* inserirBST(Node* raiz, const char* palavra, const char* definicao) {
    if (raiz == NULL) return criarNo(palavra, definicao);

    int cmp = strcmp(palavra, raiz->palavra);
    if (cmp < 0)
        raiz->esq = inserirBST(raiz->esq, palavra, definicao);
    else if (cmp > 0)
        raiz->dir = inserirBST(raiz->dir, palavra, definicao);
    // Ignora se a palavra já existe

    return raiz;
}

Node* buscarBST(Node* raiz, const char* palavra) {
    if (raiz == NULL) return NULL;

    int cmp = strcmp(palavra, raiz->palavra);
    if (cmp == 0) return raiz;
    return (cmp < 0) ? buscarBST(raiz->esq, palavra) : buscarBST(raiz->dir, palavra);
}

void imprimirPalavra(Node* no) {
    if (no != NULL) {
        printf("Palavra: %s\nDefinição: %s\n\n", no->palavra, no->definicao);
    } else {
        printf("Palavra não encontrada.\n");
    }
}

int main() {
    Node* raiz = NULL;
    raiz = inserirBST(raiz, "apple", "Fruta vermelha ou verde, doce e crocante.");
    raiz = inserirBST(raiz, "banana", "Fruta amarela, alongada e macia.");
    raiz = inserirBST(raiz, "cherry", "Pequena fruta vermelha e suculenta.");

    printf("--- Busca no Dicionário ---\n");
    imprimirPalavra(buscarBST(raiz, "banana"));  // Encontrado
    imprimirPalavra(buscarBST(raiz, "grape"));   // Não encontrado

    return 0;
}