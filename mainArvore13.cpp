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

bool verificarSoma(NoArvore*& raiz) {
    if (raiz == NULL) {
        return false;
    }

    int soma = 0;

    if (raiz->esquerda != NULL) {
        soma += raiz->esquerda->dado;
    }

    if (raiz->direita != NULL) {
        soma += raiz->direita->dado;
    }
    return soma == raiz->dado;
}

int main() {
    NoArvore* raiz = inserirNo(10);
    raiz->esquerda = inserirNo(4);
    raiz->direita = inserirNo(6);

    if (verificarSoma(raiz)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
