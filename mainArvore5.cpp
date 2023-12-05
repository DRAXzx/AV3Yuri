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

void imprimirCaminho(const int caminho[], int tamanho) {
    for (int i = 0; i < tamanho; ++i) {
        cout << caminho[i];
        if (i < tamanho - 1) {
            cout << " -> ";
        }
    }
    cout << endl;
}

void encontrarCaminhos(NoArvore* raiz, int caminho[], int posicao) {
    if (raiz == NULL) {
        return;
    }

    caminho[posicao] = raiz->dado;
    posicao++;

    if (raiz->esquerda == NULL && raiz->direita == NULL) {
        imprimirCaminho(caminho, posicao);
    } else {
        encontrarCaminhos(raiz->esquerda, caminho, posicao);
        encontrarCaminhos(raiz->direita, caminho, posicao);
    }
}

int main() {

    NoArvore* raiz = inserirNo(1);
    raiz->esquerda = inserirNo(2);
    raiz->direita = inserirNo(3);
    raiz->esquerda->esquerda = NULL;
    raiz->esquerda->direita = inserirNo(5);

    int caminho[100];

    encontrarCaminhos(raiz, caminho, 0);

    return 0;
}
