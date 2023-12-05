#include <iostream>
using namespace std;

struct NoArvore {
    int dado;
    NoArvore* esquerda;
    NoArvore* direita;
};

// Função para criar um novo nó
NoArvore* inserirNo(int valor) {
    NoArvore* novoNo = new NoArvore;
    novoNo->dado = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

NoArvore* arrayParaArvore(int arr[], int inicio, int fim) {
    if (inicio > fim) {
        return NULL;
    }

    int meio = (inicio + fim) / 2;
    NoArvore* raiz = inserirNo(arr[meio]);

    raiz->esquerda = arrayParaArvore(arr, inicio, meio - 1);
    raiz->direita = arrayParaArvore(arr, meio + 1, fim);

    return raiz;
}

void printArvore(NoArvore* raiz) {
    if (raiz != NULL) {
        printArvore(raiz->esquerda);
        cout << raiz->dado << " ";
        printArvore(raiz->direita);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    NoArvore* raiz = arrayParaArvore(arr, 0, tamanho - 1);

    cout << "Array convertido em Arvore: ";
    printArvore(raiz);
    cout << endl;

    return 0;
}
