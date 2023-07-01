#ifndef JOGODAVELHACOMARVORE_ARVORE_H
#define JOGODAVELHACOMARVORE_ARVORE_H

#include "Mapa.h"

struct Arvore {
    Mapa mapa;
    Arvore* noFilho[8];  // Ponteiros para os nós filhos da árvore

    Arvore() {
        for (int i = 0; i < 8; i++) {
            this->noFilho[i] = nullptr;
        }
    }

    void encontrarJogada();
    int Minimax(bool rodada, Arvore* noFilho);
};

int Arvore::Minimax(bool rodada, Arvore* noFilho) {
    // Verifica se o jogador 'O' venceu
    if (noFilho->mapa.Vitoria('O'))
        return 1;
    // Verifica se o jogador 'X' venceu
    if (noFilho->mapa.Vitoria('X'))
        return -1;
    // Verifica se o mapa está completamente preenchido
    if (noFilho->mapa.MapaCheio())
        return 0;

    if (rodada) {
        // Jogada de 'O': Maximizar o valor da pontuação
        int melhorPonto = -1;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (noFilho->mapa.Get(i, j) == ' ') {
                    noFilho->mapa.Set(i, j, 'O');
                    int score = Minimax(false, noFilho);
                    noFilho->mapa.Set(i, j, ' ');
                    if (score > melhorPonto) {
                        melhorPonto = score;
                    }
                }
            }
        }
        return melhorPonto;
    } else {
        // Jogada de 'X': Minimizar o valor da pontuação
        int melhorPonto = 1;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (noFilho->mapa.Get(i, j) == ' ') {
                    noFilho->mapa.Set(i, j, 'X');
                    int score = Minimax(true, noFilho);
                    noFilho->mapa.Set(i, j, ' ');
                    if (score < melhorPonto) {
                        melhorPonto = score;
                    }
                }
            }
        }
        return melhorPonto;
    }
}

void Arvore::encontrarJogada() {
    int melhorPonto = -1;
    int linha = -1;
    int coluna = -1;
    int numNo = 0;
    // Cria cópias dos nós filhos para testar as jogadas possíveis
    for (int i = 0; i < 8; ++i) {
        this->noFilho[i] = new Arvore;
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                this->noFilho[i]->mapa.Set(j, k, this->mapa.Get(j, k));
            }
        }
    }

    // Encontra a melhor jogada para a IA percorrendo todas as posições vazias
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (this->mapa.Get(i, j) == ' ') {
                this->noFilho[numNo]->mapa.Set(i, j, 'O');
                int ponto = Minimax(false, this->noFilho[numNo]);
                this->noFilho[numNo]->mapa.Set(i, j, ' ');
                if (ponto > melhorPonto) {
                    melhorPonto = ponto;
                    linha = i;
                    coluna = j;
                }
                numNo++;
            }
        }
    }
    // Realiza a melhor jogada para a IA
    this->mapa.Set(linha, coluna, 'O');
}

#endif // JOGODAVELHACOMARVORE_ARVORE_H
