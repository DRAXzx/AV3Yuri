#include <iostream>
using namespace std;

struct NoArvore {
    int dado;
    NoArvore* esquerda;
    NoArvore* direita;
};

// Fun��o para criar um novo n�
NoArvore* criarNo(int valor) {
    NoArvore* novoNo = new NoArvore;
    novoNo->dado = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Fun��o para encontrar o maior n� de cada n�vel
void maiorNoPorNivel(NoArvore* raiz) {
    if (raiz == NULL) {
        return;
    }

    while (raiz != NULL) {
        NoArvore* temp = raiz;
        int maiorValor = temp->dado; // Inicializando com o valor do n� atual

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

        cout << "Maior n� do n�vel: " << maiorValor << endl;
        raiz = raiz->esquerda; // Move para o pr�ximo n�vel
    }
}

int main() {
    // Criando a �rvore com os n�s fornecidos
    NoArvore* raiz = criarNo(1);
    raiz->esquerda = criarNo(3);
    raiz->direita = criarNo(2);
    raiz->esquerda->esquerda = criarNo(5);
    raiz->esquerda->direita = criarNo(3);
    raiz->direita->direita = criarNo(9);

    // Encontrando e imprimindo o maior n� de cada n�vel
    maiorNoPorNivel(raiz);

    return 0;
}
