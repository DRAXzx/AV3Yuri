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

bool estaBalanceada(NoArvore* raiz) {
    if (raiz == NULL) {
        return true; 
    }

    int alturaEsquerda = alturaArvore(raiz->esquerda);
    int alturaDireita = alturaArvore(raiz->direita);

    if ((alturaEsquerda - alturaDireita) <= 1 && estaBalanceada(raiz->esquerda) && estaBalanceada(raiz->direita)) {
        return true;
    }

    return false;
}

int main() {

    NoArvore* raiz = inserirNo(1);
    raiz->esquerda = inserirNo(2);
    raiz->direita = inserirNo(3);
    raiz->esquerda->esquerda = inserirNo(4);
    raiz->esquerda->direita = inserirNo(5);

   if (estaBalanceada(raiz)) {
        cout << "A arvore esta balanceada." << endl;
    } else {
        cout << "A arvore nao esta balanceada." << endl;
    }

    return 0;
}
