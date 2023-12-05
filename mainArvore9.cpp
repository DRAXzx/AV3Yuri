#include <iostream>
using namespace std;

struct NoArvore {
    int dado;
    NoArvore* esquerda;
    NoArvore* direita;
};

int alturaArvore(NoArvore* raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        int alturaEsquerda = alturaArvore(raiz->esquerda);
        int alturaDireita = alturaArvore(raiz->direita);
        return max(alturaEsquerda, alturaDireita) + 1;
    }
}

NoArvore* criarNo(int dado) {
    NoArvore* novoNo = new NoArvore;
    novoNo->dado = dado;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

NoArvore* rotacaoDireita(NoArvore* desbalanceado) {
    NoArvore* novoPai = desbalanceado->esquerda;
    desbalanceado->esquerda = novoPai->direita;
    novoPai->direita = desbalanceado;
    return novoPai;
}

NoArvore* rotacaoEsquerda(NoArvore* desbalanceado) {
    NoArvore* novoPai = desbalanceado->direita;
    desbalanceado->direita = novoPai->esquerda;
    novoPai->esquerda = desbalanceado;
    return novoPai;
}

NoArvore* balancearArvore(NoArvore* raiz) {
    if (raiz == NULL) {
        return NULL;
    }

    if (alturaArvore(raiz->esquerda) - alturaArvore(raiz->direita) > 1) {
        if (alturaArvore(raiz->esquerda->direita) > alturaArvore(raiz->esquerda->esquerda)) {
            raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        }
        raiz = rotacaoDireita(raiz);
    } else if (alturaArvore(raiz->direita) - alturaArvore(raiz->esquerda) > 1) {
        if (alturaArvore(raiz->direita->esquerda) > alturaArvore(raiz->direita->direita)) {
            raiz->direita = rotacaoDireita(raiz->direita);
        }
        raiz = rotacaoEsquerda(raiz);
    }

    raiz->esquerda = balancearArvore(raiz->esquerda);
    raiz->direita = balancearArvore(raiz->direita);

    return raiz;
}

void printArvore(NoArvore* raiz) {
    if (raiz != NULL) {
        printArvore(raiz->esquerda);
        cout << raiz->dado << " ";
        printArvore(raiz->direita);
    }
}

int main() {

    NoArvore* raiz = criarNo(1);
    raiz->esquerda = criarNo(2);
    raiz->esquerda->esquerda = criarNo(3);
    raiz->esquerda->esquerda->esquerda = criarNo(4);

    raiz = balancearArvore(raiz);

    cout << "Arvore esta balanceada : ";
    cout << endl;

    return 0;
}
