#include <iostream>
using namespace std;

struct NoArvore {
    int dado;
    NoArvore* esquerda;
    NoArvore* direita;
};

NoArvore* criarNo(int valor) {
    NoArvore* novoNo = new NoArvore;
    novoNo->dado = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

NoArvore* inserirNo(NoArvore* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }

    if (valor < raiz->dado) {
        raiz->esquerda = inserirNo(raiz->esquerda, valor);
    } else if (valor > raiz->dado) {
        raiz->direita = inserirNo(raiz->direita, valor);
    }

    return raiz;
}

NoArvore* encontrarMenorNo(NoArvore* raiz) {
    if (raiz == NULL) {
        return NULL;
    }

    while (raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }

    return raiz;
}

int main() {
    NoArvore* raiz = NULL;

    raiz = inserirNo(raiz, 4);
    inserirNo(raiz, 2);
    inserirNo(raiz, 6);
    inserirNo(raiz, 1);
    inserirNo(raiz, 3);
    inserirNo(raiz, 5);
    inserirNo(raiz, 7);

    NoArvore* menorNo = encontrarMenorNo(raiz);

    if (menorNo != NULL) {
        cout << "Menor no da arvore: " << menorNo->dado << endl;
    } else {
        cout << "A arvore esta vazia." << endl;
    }

    return 0;
}
