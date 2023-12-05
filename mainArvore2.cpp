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

bool saoIguais(NoArvore* raiz1, NoArvore* raiz2) {
    if (raiz1 == NULL && raiz2 == NULL) {
        return true;
    }
    if (raiz1 != NULL && raiz2 != NULL) {
        return (raiz1->dado == raiz2->dado) &&
               saoIguais(raiz1->esquerda, raiz2->esquerda) &&
               saoIguais(raiz1->direita, raiz2->direita);
    }
    return false;
}

int main() {

    NoArvore* raiz1 = inserirNo(1);
    raiz1->esquerda = inserirNo(2);
    raiz1->direita = inserirNo(3);

    NoArvore* raiz2 = inserirNo(1);
    raiz2->esquerda = inserirNo(2);
    raiz2->direita = inserirNo(3);

    if (saoIguais(raiz1, raiz2)) {
        cout << "As arvores sao iguais." << endl;
    } else {
        cout << "As arvores nao sao iguais." << endl;
    }

    return 0;
}
