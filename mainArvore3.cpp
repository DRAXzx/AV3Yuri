#include <iostream>
using namespace std;

struct NoArvore {
    int dado;
    NoArvore* esquerda;
    NoArvore* direita;
};

NoArvore* criarNo(int dado) {
    NoArvore* novoNo = new NoArvore;
    novoNo->dado = dado;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

void posOrdem(NoArvore* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        cout << raiz->dado << " ";
    }
}

int main() {

    NoArvore* raiz = criarNo(1);
    raiz->esquerda = NULL;
    raiz->direita = criarNo(2);
    raiz->direita->esquerda = criarNo(3);

    cout << "Nos em pos-ordem: ";
    posOrdem(raiz);
    cout << endl;

    return 0;
}
