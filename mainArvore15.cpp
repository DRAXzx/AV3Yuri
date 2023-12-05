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

int somaNosFolhas(NoArvore* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    if (raiz->esquerda == NULL && raiz->direita == NULL) {
        return raiz->dado;
    }
    return somaNosFolhas(raiz->esquerda) + somaNosFolhas(raiz->direita);
}

int main() {

    NoArvore* raiz = inserirNo(10);
    raiz->esquerda = inserirNo(5);
    raiz->direita = inserirNo(15);
    raiz->esquerda->esquerda = inserirNo(3);
    raiz->esquerda->direita = inserirNo(7);
    raiz->direita->esquerda = inserirNo(12);
    raiz->direita->direita = inserirNo(18);

    cout << "Soma dos nos folhas: " << somaNosFolhas(raiz) << endl;

    return 0;
}
