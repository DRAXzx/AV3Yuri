#include <iostream>
using namespace std;

struct NoArvore {
    int dado;
    NoArvore* esquerda;
    NoArvore* direita;
};


NoArvore* criarNo(int valor) {
    NoArvore* novoNo = new NoArvore;
    novoNo->dado = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

void maiorNoPorNivel(NoArvore* raiz) {
    if (raiz == NULL) {
        return;
    }

    while (raiz != NULL) {
        NoArvore* temp = raiz;
        int maiorValor = temp->dado; 

        while (temp != NULL) {
            if (temp->dado > maiorValor) {
                maiorValor = temp->dado;
            }

            if (temp->esquerda != NULL) {
                temp = temp->esquerda;
            } else {
                temp = temp->direita;
            }
        }

        cout << "Maior nó do nível: " << maiorValor << endl;
        raiz = raiz->esquerda; 
    }
}

int main() {

    NoArvore* raiz = criarNo(1);
    raiz->esquerda = criarNo(3);
    raiz->direita = criarNo(2);
    raiz->esquerda->esquerda = criarNo(5);
    raiz->esquerda->direita = criarNo(3);
    raiz->direita->esquerda = NULL;
    raiz->direita->direita = criarNo(9);

    maiorNoPorNivel(raiz);

    return 0;
}
