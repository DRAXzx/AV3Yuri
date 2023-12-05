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

int alturaArvore(NoArvore* raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        int alturaEsquerda = alturaArvore(raiz->esquerda);
        int alturaDireita = alturaArvore(raiz->direita);

        return max(alturaEsquerda, alturaDireita) + 1;
    }
}

int main() {

    NoArvore* raiz = inserirNo(1);
    raiz->esquerda = inserirNo(2);
    raiz->direita = inserirNo(3);
    raiz->esquerda->esquerda = inserirNo(4);
    raiz->esquerda->direita = inserirNo(5);
    raiz->direita->esquerda = inserirNo(6);
    raiz->direita->direita = inserirNo(7);
    raiz->esquerda->esquerda->esquerda = inserirNo(8);
    raiz->esquerda->esquerda->direita = inserirNo(9);
    raiz->direita->direita->direita = inserirNo(10);

    int altura = alturaArvore(raiz);
    cout << "Altura da arvore: " << altura << endl;

    return 0;
}
