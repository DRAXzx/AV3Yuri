#include <iostream>
using namespace std;

struct NoArvore {
    int dado;
    NoArvore* esquerda;
    NoArvore* direita;
};

NoArvore* inserirNo(int dado) {
    NoArvore* novoNo = new NoArvore;
    novoNo->dado = dado;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

void preOrdem(NoArvore* raiz) {
    if (raiz != NULL) {
        cout << raiz->dado << " ";
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

int main() {

    NoArvore* raiz = inserirNo(1);
    raiz->esquerda = NULL;
    raiz->direita = inserirNo(2);
    raiz->direita->esquerda = inserirNo(3);

    cout << "Nos em pre-ordem: ";
    preOrdem(raiz);
    cout << endl;

    return 0;
}
