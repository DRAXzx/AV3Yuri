#include <iostream>

using namespace std;

struct NoArvore {
    int dado;
    NoArvore* primeiroFilho;
    NoArvore* proximoIrmao;
};

NoArvore* inserirNo(int valor) {
    NoArvore* novoNo = new NoArvore;
    novoNo->dado = valor;
    novoNo->primeiroFilho = NULL;
    novoNo->proximoIrmao = NULL;
    return novoNo;
}

void percorrerPosOrdem(NoArvore* raiz) {
    if (raiz != NULL) {
        percorrerPosOrdem(raiz->primeiroFilho);

        cout << raiz->dado << " ";

        percorrerPosOrdem(raiz->proximoIrmao);
    }
}

int main() {

    NoArvore* raiz = inserirNo(1);
    raiz->primeiroFilho = inserirNo(2);
    raiz->primeiroFilho->proximoIrmao = inserirNo(3);
    raiz->primeiroFilho->proximoIrmao->proximoIrmao = inserirNo(4);

    raiz->primeiroFilho->primeiroFilho = inserirNo(5);
    raiz->primeiroFilho->primeiroFilho->proximoIrmao = inserirNo(6);

    raiz->primeiroFilho->proximoIrmao->primeiroFilho = inserirNo(7);
    raiz->primeiroFilho->proximoIrmao->primeiroFilho->proximoIrmao = inserirNo(8);

    cout << "Nos em pos-ordem: ";
    percorrerPosOrdem(raiz);
    cout << endl;

    return 0;
}
