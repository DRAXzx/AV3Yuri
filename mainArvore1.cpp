#include <iostream>
using namespace std;

struct NoArvore {
    int dado;
    NoArvore *esquerda;
    NoArvore *direita;
};

NoArvore* inserirNo(int valor) {
    NoArvore* novoNo = new NoArvore;
    novoNo->dado = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

void imprimirArvore(NoArvore *&raiz) {
    if (raiz != NULL) {
        imprimirArvore(raiz->esquerda);
        cout << raiz->dado << " ";
        imprimirArvore(raiz->direita);
    }
}

int main() {
    NoArvore *raiz = inserirNo(1);
    raiz->esquerda = NULL;
    raiz->direita = inserirNo(2);
    raiz->direita->esquerda = inserirNo(3);

    cout << "Árvore em ordem: " << endl;
    imprimirArvore(raiz);

    return 0;
}
