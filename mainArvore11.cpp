#include <iostream>
using namespace std;

struct NoArvore{
    int dado;
    NoArvore *esquerda;
    NoArvore *direita;
};

NoArvore* inserirNo(int valor) {
    NoArvore* novoNo = new NoArvore;
    novoNo->dado = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

void inverter(NoArvore *raiz){
    if(raiz == NULL){
        return;
    }
    NoArvore *temp = raiz->esquerda;
    raiz->esquerda = raiz->direita;
    raiz->direita = temp;

    inverter(raiz->esquerda);
    inverter(raiz->direita);
}

void imprimirArvore(NoArvore *&raiz){
    if(raiz != NULL){
        cout << raiz->dado << " ";
        imprimirArvore(raiz->esquerda);
        imprimirArvore(raiz->direita);
    }
}

int main(){
    
	NoArvore *raiz = inserirNo(4);
    raiz->esquerda = inserirNo(2);
    raiz->direita = inserirNo(7);
    raiz->esquerda->esquerda = inserirNo(1);
    raiz->esquerda->direita = inserirNo(3);
    raiz->direita->esquerda = inserirNo(6);
    raiz->direita->direita = inserirNo(9);

    inverter(raiz);
    cout << "Arvore invertida: " << endl;
    imprimirArvore(raiz);

    return 0;
}
