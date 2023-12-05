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

int somaSubArvore(NoArvore* raiz, int& maiorValor) {
    if (raiz == NULL) {
        return 0;
    }

    int somaEsquerda = somaSubArvore(raiz->esquerda, maiorValor);
    int somaDireita = somaSubArvore(raiz->direita, maiorValor);

    int valorSoma = raiz->dado + somaEsquerda + somaDireita;

    maiorValor = max(maiorValor, valorSoma);

    return max(raiz->dado, raiz->dado + max(somaEsquerda, somaDireita));
}

int maxSubArvore(NoArvore* raiz) {
    int maiorValor = -2147483648;
    somaSubArvore(raiz, maiorValor);
    return maiorValor;
}

void printArvore(NoArvore*& raiz) {
    if (raiz != NULL) {
        cout << raiz->dado << " ";
        printArvore(raiz->esquerda);
        printArvore(raiz->direita);
    }
}

int main() {
    NoArvore* raiz = inserirNo(1);
    raiz->esquerda = inserirNo(4);
    raiz->direita = inserirNo(3);
    raiz->esquerda->esquerda = inserirNo(2);
    raiz->esquerda->direita = inserirNo(4);
    raiz->direita->esquerda = inserirNo(2);
    raiz->direita->direita = inserirNo(5);
    raiz->direita->direita->esquerda = inserirNo(4);
    raiz->direita->direita->direita = inserirNo(6);

    printArvore(raiz);
    cout << endl;

    int maxSoma = maxSubArvore(raiz);
    cout << "Maior Soma: " << maxSoma << endl;

    return 0;
}
