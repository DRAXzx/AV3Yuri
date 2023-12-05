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

int profundidadeArvore(NoArvore* raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        int profundidadeEsquerda = profundidadeArvore(raiz->esquerda);
        int profundidadeDireita = profundidadeArvore(raiz->direita);

        return max(profundidadeEsquerda, profundidadeDireita) + 1;
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

    int profundidade = profundidadeArvore(raiz);
    cout << "Profundidade da arvore: " << profundidade << endl;

    return 0;
}
