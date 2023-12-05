#include <iostream>
using namespace std;

struct NoArvore {
    int dado;
    NoArvore* esquerda;
    NoArvore* direita;
};

NoArvore* inserirNo(int valor) {
    NoArvore* novoNo = new NoArvore;
    novoNo->dado = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

NoArvore* inserirNo(NoArvore* raiz, int valor) {
    if (raiz == NULL) {
        return inserirNo(valor);
    }

    if (valor < raiz->dado) {
        raiz->esquerda = inserirNo(raiz->esquerda, valor);
    } else if (valor > raiz->dado) {
        raiz->direita = inserirNo(raiz->direita, valor);
    }

    return raiz;
}

NoArvore* buscarNo(NoArvore* raiz, int valor) {
    if (raiz == NULL || raiz->dado == valor) {
        return raiz;
    }

    if (valor < raiz->dado) {
        return buscarNo(raiz->esquerda, valor);
    }

    return buscarNo(raiz->direita, valor);
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

    int valorBuscado = 3;

    NoArvore* noEncontrado = buscarNo(raiz, valorBuscado);

    if (noEncontrado != NULL) {
        cout << "Valor " << valorBuscado << " encontrado na arvore." << endl;
    } else {
        cout << "Valor " << valorBuscado << " nao encontrado na arvore." << endl;
    }

    return 0;
}
