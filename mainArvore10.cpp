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

bool ehBST(NoArvore* raiz, int minValor = INT_MIN, int maxValor = INT_MAX) {
    if (raiz == NULL) {
        return true; 
    }

    if (raiz->dado <= minValor || raiz->dado >= maxValor) {
        return false;
    }

    return ehBST(raiz->esquerda, minValor, raiz->dado) && ehBST(raiz->direita, raiz->dado, maxValor);
}

int main() {

    NoArvore* raizBST = inserirNo(1);
    raizBST->esquerda = inserirNo(2);
    raizBST->direita = inserirNo(3);

   if (ehBST(raizBST)) {
        cout << "A arvore e uma BST." << endl;
    } else {
        cout << "A arvore nao e uma BST." << endl;
    }

    return 0;
}
