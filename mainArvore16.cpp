#include <iostream>
using namespace std;

struct NoArvore {
    int dado;
    NoArvore* esquerda;
    NoArvore* direita;
};

// Função para criar um novo nó
NoArvore* criarNo(int valor) {
    NoArvore* novoNo = new NoArvore;
    novoNo->dado = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função para encontrar o maior nó de cada nível
void maiorNoPorNivel(NoArvore* raiz) {
    if (raiz == NULL) {
        return;
    }

    while (raiz != NULL) {
        NoArvore* temp = raiz;
        int maiorValor = temp->dado; // Inicializando com o valor do nó atual

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
        raiz = raiz->esquerda; // Move para o próximo nível
    }
}

int main() {
    // Criando a árvore com os nós fornecidos
    NoArvore* raiz = criarNo(1);
    raiz->esquerda = criarNo(3);
    raiz->direita = criarNo(2);
    raiz->esquerda->esquerda = criarNo(5);
    raiz->esquerda->direita = criarNo(3);
    raiz->direita->esquerda = NULL;
    raiz->direita->direita = criarNo(9);

    // Encontrando e imprimindo o maior nó de cada nível
    maiorNoPorNivel(raiz);

    return 0;
}
