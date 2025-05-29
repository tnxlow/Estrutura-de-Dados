#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int valor;
    struct Node* esq;
    struct Node* dir;
} Node;

Node* criarNo(int valor) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->valor = valor;
    novo->esq = novo->dir = NULL;
    return novo;
}

void inserirNivel(Node** raiz, int valor) {
    Node* novo = criarNo(valor);
    if (*raiz == NULL) {
        *raiz = novo;
        return;
    }

    Node* fila[MAX];
    int inicio = 0, fim = 0;
    fila[fim++] = *raiz;

    while (inicio < fim) {
        Node* atual = fila[inicio++];

        if (atual->esq == NULL) {
            atual->esq = novo;
            return;
        } else {
            fila[fim++] = atual->esq;
        }

        if (atual->dir == NULL) {
            atual->dir = novo;
            return;
        } else {
            fila[fim++] = atual->dir;
        }
    }
}

Node* inserirBST(Node* raiz, int valor) {
    if (raiz == NULL) return criarNo(valor);

    if (valor < raiz->valor)
        raiz->esq = inserirBST(raiz->esq, valor);
    else
        raiz->dir = inserirBST(raiz->dir, valor);

    return raiz;
}

void preOrdem(Node* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

int main() {
    int opcao;
    printf("Escolha o tipo de árvore:\n");
    printf("1 - Árvore Binária (inserção por nível)\n");
    printf("2 - Árvore Binária de Busca (BST)\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    Node* raiz = NULL;

    if (opcao == 1) {
        int dados[] = {15, 10, 20, 8, 12, 17, 25};
        int n = sizeof(dados) / sizeof(dados[0]);

        for (int i = 0; i < n; i++) {
            inserirNivel(&raiz, dados[i]);
        }

        printf("Pre-ordem (Árvore Binária): ");
        preOrdem(raiz);
        printf("\n");

    } else if (opcao == 2) {
        int dados[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45};
        int n = sizeof(dados) / sizeof(dados[0]);

        for (int i = 0; i < n; i++) {
            raiz = inserirBST(raiz, dados[i]);
        }

        printf("Pre-ordem (BST): ");
        preOrdem(raiz);
        printf("\n");

    } else {
        printf("Opção inválida.\n");
    }

    return 0;
}
