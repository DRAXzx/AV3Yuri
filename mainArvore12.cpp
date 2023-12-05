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

NoArvore* merge(NoArvore* raiz1, NoArvore* raiz2) {
    if (raiz1 == NULL) {
        return raiz2;
    }
    if (raiz2 == NULL) {
        return raiz1;
    }

    NoArvore* novoNo = inserirNo(raiz1->dado + raiz2->dado);

    novoNo->esquerda = merge(raiz1->esquerda, raiz2->esquerda);
    novoNo->direita = merge(raiz1->direita, raiz2->direita);

    return novoNo;
}

void printArvore(NoArvore*& raiz) {
    if (raiz != NULL) {
        cout << raiz->dado << " ";
        printArvore(raiz->esquerda);
        printArvore(raiz->direita);
    }
}

int main() {
    NoArvore* raiz1 = inserirNo(1);
    raiz1->esquerda = inserirNo(3);
    raiz1->direita = inserirNo(2);
    raiz1->esquerda->esquerda = inserirNo(5);

    NoArvore* raiz2 = inserirNo(2);
    raiz2->esquerda = inserirNo(1);
    raiz2->direita = inserirNo(3);
    raiz2->esquerda->direita = inserirNo(4);
    raiz2->direita->direita = inserirNo(7);
    
    cout << "Raiz1: ";
    printArvore(raiz1);
    cout << endl;
    
    cout << "Raiz2: ";
    printArvore(raiz2);
    cout << endl;

    NoArvore* mergeArvore = merge(raiz1, raiz2);
    cout << "Merge de Raiz1 e Raiz2: " << endl;
    printArvore(mergeArvore);

    return 0;
}
